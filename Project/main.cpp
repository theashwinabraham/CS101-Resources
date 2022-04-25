/*
* MODIFIED BY: ASHWIN ABRAHAM
*/
#include <simplecpp>
#include <ctime>
#include "shooter.h"
#include "bubble.h"

/* Simulation Vars */
const double STEP_TIME = 0.005;
int level = 1; //levels go from 1 to 5
double TOTAL_TIME = 240 - 30*level; //in level n, the time given to complete the level is 240 - 30*n (210, 180, 150, 120, 90)
double time_left = TOTAL_TIME;
int score = 0;
int HEALTH_MAX = 8 - level; //in level n, the initial health given to complete the level is 8 - n (7, 6, 5, 4, 3)
const vector<vector<int>> bubble_colors = {{0, 200, 255}, {155, 255, 0}, {0, 255, 0}, {120, 30, 155}, {143, 0, 255}};
int health = HEALTH_MAX;


/* Game Vars */
//const int PLAY_Y_HEIGHT = 450;
const int LEFT_MARGIN = 70;
const int TOP_MARGIN = 20;
const int BOTTOM_MARGIN = (PLAY_Y_HEIGHT+TOP_MARGIN);

string to_string(int num){
//converts a non-negative int to a string
    if(num==0){return "0";}
    int reversed_num = 0;
    int num_trailing_zeroes = 0;
    while(num%10 == 0){
        num_trailing_zeroes++;
        num/=10;
    }
    while(num>0){
        reversed_num = 10*reversed_num + (num%10);
        num/=10;
    }
    string str = "";
    while(reversed_num>0){
        char ch = (reversed_num%10) + '0';
        str+=ch;
        reversed_num/=10;
    }
    for(int i = 0; i<num_trailing_zeroes; i++){str+='0';}
    return str;
}

void bubble_bullet_collision(vector<Bubble> &bubbles, vector<Bullet> &bullets, int& score, Text& Score){
    //checks if the bubbles and bullets collide with each other
    for(unsigned int i = 0; i<bullets.size(); i++){
        for(unsigned int j = 0; j<bubbles.size(); j++){
            if(abs(bubbles[j].get_center_x() - bullets[i].get_center_x())< bubbles[j].get_radius() + bullets[i].get_width()/2
            && abs(bubbles[j].get_center_y() - bullets[i].get_center_y())< bubbles[j].get_radius() + bullets[i].get_height()/2){
                if(abs(bubbles[j].get_radius()-2*BUBBLE_DEFAULT_RADIUS)<1e-3){
                    bubbles.push_back(Bubble(bubbles[j].get_center_x(), bubbles[j].get_center_y(), BUBBLE_DEFAULT_RADIUS, -bubbles[j].get_vx(), bubbles[j].get_vy(), COLOR(bubble_colors[level-1][0], bubble_colors[level-1][1], bubble_colors[level-1][2])));
                    bubbles.push_back(Bubble(bubbles[j].get_center_x(), bubbles[j].get_center_y(), BUBBLE_DEFAULT_RADIUS, 2*bubbles[j].get_vx(), bubbles[j].get_vy(), COLOR(bubble_colors[level-1][0], bubble_colors[level-1][1], bubble_colors[level-1][2])));
                    score--;
                }
                bubbles.erase(bubbles.begin()+j);
                bullets.erase(bullets.begin()+i);
                score+=2;
                Score.setMessage(to_string(score));
                return;
            }
        }
    }
    return;
}

bool bubble_shooter_collision(vector<Bubble>& bubbles, Shooter& shooter, int& health, Text& Health, bool& is_in_collision){
//checks if a bubble collides with a shooter
    for(unsigned int i = 0; i<bubbles.size(); i++){
        if(abs(bubbles[i].get_center_x()-shooter.get_body_center_x())<bubbles[i].get_radius()+shooter.get_body_width()/2
        && abs(bubbles[i].get_center_y()-shooter.get_body_center_y())<bubbles[i].get_radius()+shooter.get_body_height()/2+
            2*shooter.get_head_radius()){
                if(!is_in_collision){
                    health--;
                    Health.setMessage(to_string(health));
                    is_in_collision = true;
                }
                return true;
            }
        }
    return false;
}



void move_bullets(vector<Bullet> &bullets){
    // move all bullets
    for(unsigned int i=0; i<bullets.size(); i++){
        if(!bullets[i].nextStep(STEP_TIME)){
            bullets.erase(bullets.begin()+i);
        }
    }
}

void move_bubbles(vector<Bubble> &bubbles){
    // move all bubbles
    for (unsigned int i=0; i < bubbles.size(); i++)
    {
        bubbles[i].nextStep(STEP_TIME, 0.95 + 0.05*level);
    }
}

vector<Bubble> create_bubbles()
{
    // create initial bubbles in the game
    vector<Bubble> bubbles;

    for(int i = 0; i<level; i++){
        bubbles.push_back(Bubble(WINDOW_X*(2*i+1)/(2*level + 1), BUBBLE_START_Y, 2*BUBBLE_DEFAULT_RADIUS, -level*BUBBLE_DEFAULT_VX, 0, COLOR(bubble_colors[level-1][0], bubble_colors[level-1][1], bubble_colors[level-1][2])));
        bubbles.push_back(Bubble(WINDOW_X*(2*i + 2)/(2*level + 1), BUBBLE_START_Y, 2*BUBBLE_DEFAULT_RADIUS, level*BUBBLE_DEFAULT_VX, 0, COLOR(bubble_colors[level-1][0], bubble_colors[level-1][1], bubble_colors[level-1][2])));
        }
    return bubbles;
}


int main(){
    initCanvas("Bubble Trouble", WINDOW_X, WINDOW_Y);

    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
    b1.setColor(COLOR(0, 0, 255));
    string msg_cmd("Cmd: _");
    Text charPressed(LEFT_MARGIN, BOTTOM_MARGIN, msg_cmd);

    // Intialize the shooter
    Shooter shooter(SHOOTER_START_X, SHOOTER_START_Y, SHOOTER_VX);

    Text update(WINDOW_X/2, WINDOW_Y/2, "Welcome to Bubble Trouble!");
    wait(2);
    update.setMessage("Press 'a' and 'd' to move left and right");
    wait(2);
    update.setMessage("Press 'w' to fire a Bullet");
    wait(2);
    update.setMessage("Destroy all the Bubbles to proceed to the next level");
    wait(2);
    update.setMessage("Large Bubbles are worth one point and Small Bubbles are worth two points");
    wait(2);
    update.setMessage("Your Health Decreases when a Bubble hits you");
    wait(2);
    update.setMessage("The Game ends when your Health becomes 0 or if you run out of time");
    wait(2);
    update.setMessage("Enjoy Playing!");
    wait(2);
    update.hide();

    // Initialize the bubbles
    vector<Bubble> bubbles = create_bubbles();

    // Initialize the bullets (empty)
    vector<Bullet> bullets;
    XEvent event;
    //prints the time remaining
    Text Time_message(LEFT_MARGIN + 100, BOTTOM_MARGIN, "Time Remaining: ");
    Text Time(LEFT_MARGIN + 170, BOTTOM_MARGIN, time_left);

    //prints the current score
    Text Score_message(LEFT_MARGIN + 220, BOTTOM_MARGIN, "Score: ");
    Text Score(LEFT_MARGIN + 250, BOTTOM_MARGIN, score);

    //prints the current health
    Text Health_message(LEFT_MARGIN + 290, BOTTOM_MARGIN, "Health: ");
    Text Health(LEFT_MARGIN + 320, BOTTOM_MARGIN, health);

    //prints the current level
    Text Level_message(LEFT_MARGIN + 360, BOTTOM_MARGIN, "Level: ");
    Text Level(LEFT_MARGIN + 390, BOTTOM_MARGIN, level);

    bool is_in_collision = false; //this variable prevents health from draining in every loop when the bubble collides with the shooter

    time_t init_time = time(NULL);
    // Main game loop
    while (true){
        bool pendingEvent = checkEvent(event);
        if (pendingEvent)
        {
            // Get the key pressed
            char c = charFromEvent(event);
            msg_cmd[msg_cmd.length() - 1] = c;
            charPressed.setMessage(msg_cmd);

            // Update the shooter
            if(c == 'a')
                shooter.move(STEP_TIME, true);
            else if(c == 'd')
                shooter.move(STEP_TIME, false);
            else if(c == 'w')
                bullets.push_back(shooter.shoot());
            else if(c == 'q'){
                cout << "You have succesfully exited the game";
                return 0;
            }
        }
        //checking if bubbles collide with bullets
        bubble_bullet_collision(bubbles, bullets, score, Score);
        //checking if the bubble collides with the Shooter
        if(!bubble_shooter_collision(bubbles, shooter, health, Health, is_in_collision)){
            is_in_collision = false;
        }


        //goes to the next level when all bubbles are destroyed
        //ends game on level 5
        if(bubbles.size()==0){
            if(level == 5){
                update.setMessage("Congratulations, you have won!");
                update.setColor(COLOR("green"));
                update.show();
                cout << "Congratulations, you have won!" << endl << "Your score is: " << score;
                wait(5);
                return 0;
            }
            level++;
            TOTAL_TIME-=30;
            HEALTH_MAX--;
            Level.setMessage(to_string(level));
            bullets = {};
            health = HEALTH_MAX;
            Health.setMessage(to_string(health));
            init_time = time(NULL);
            time_left = TOTAL_TIME;
            Time.setMessage(to_string(time_left));
            shooter.center();
            update.setMessage("Level "+to_string(level));
            update.setColor(COLOR("green"));
            update.show();
            wait(3);
            update.hide();
            bubbles = create_bubbles();
        }

        //ends game when time or health runs out
        if(time_left<=0 || health <=0){
            update.setMessage("GAME OVER");
            update.setColor(COLOR("red"));
            update.show();
            wait(5);
            cout << "Your score is: " << score << endl << "You have lost...";
            return 0;
        }


        // Update the bubbles
        move_bubbles(bubbles);

        // Update the bullets
        move_bullets(bullets);

        wait(STEP_TIME);
        time_left = TOTAL_TIME + init_time - time(NULL);
        Time.setMessage(to_string(time_left));
    }
    return 0;
}
