Project Name: Bubble Trouble
Designed by: Ashwin Abraham (Roll No: 210050023)

Link to Project Specifications: https://docs.google.com/document/d/e/2PACX-1vQ0ame63KZTG2R3mtjqwqj2ei20IahKe6CLt2WaCQlJFHCLf3FILMY_JFMrNTvVGb5nyTi3CvGuSBOG/pub

Link to the Screen Recording: https://drive.google.com/drive/folders/14rpvy25VVuqSpUmfMGUsVmPfY9SkbI-E?usp=sharing


Features added:

1. The game now has 5 levels. You win the game only by successfully completing all 5 levels. Each level increases
   in difficulty. The only way to go from one level to another is by destroying all the Bubbles in the current
   level.

2. Bubbles now travel in Parabolic Paths and bounce off the walls and the floors. The number and speed of the 
   Bubbles increases in each level and the coefficient of restitution for collisions between the Bubbles and the
   floor is more than 1 for levels above level 1, increasing the difficulty. The colors of the Bubbles
   also change from level to level.

3. There are 2 types of Bubbles, large Bubbles and small Bubbles. The small Bubbles have radius half that of the 
   large Bubbles. When a Bullet collides with a large Bubble, it splits into 2 small Bubbles moving in opposite 
   directions, and when a Bullet collides with a small Bubble, the Bubble dissappears. Whenever a Bullet collides 
   with any Bubble, the Bullet dissappears too.

4. Added a Health counter for the Shooter. When a Bubble collides with the Shooter, the Health of the Shooter 
   decreases by 1. When the Health becomes 0, you lose, it is Game Over, and the Game Ends. The health resets 
   every level and the starting Health of the Shooter decreases each level.

5. Added a Score counter. When a Bullet collides with a large Bubble, the Score increases by 1, and when it 
   collides with a small Bubble, the Score increases by 2. The Score does not reset every level.

6. Added a Timer which displays the time remaining (in seconds) to complete each level. The time given to complete
   each level decreases in each level, and the Timer resets after finishing each level. If you run out of time in a
   level, you lose, it is Game Over, and the Game Ends.

7. The Timer, Score, Health and Current Level are all displayed on the bottom of the Canvas.

8. When the Game Ends, the Canvas closes. The Score on ending is displayed on the Console, and it also prints 
   out whether you have won or lost.


To play the game (Starter Code Features):

1. The Canvas opens on running the code and the game starts on Level 1.

2. To move the shooter left, click 'A' and to move it right click 'D'. To fire a Bullet, press 'W'.
