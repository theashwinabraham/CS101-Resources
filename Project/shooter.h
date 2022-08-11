/*
* MODIFIED BY: ASHWIN ABRAHAM
*/
#include <simplecpp>
#include "bullet.h"

/* Shooter Vars */
const int SHOOTER_START_X = 250;
const int SHOOTER_START_Y = 425;
const int SHOOTER_VX = 400;

/* Game Window Vars */
const int WINDOW_X = 500;
const int WINDOW_Y = 500;


class Shooter
{
private:
    Rectangle body; // The body of the shooter
    Circle head;    // The head of the shooter
    double vx;      // The x-velocity of the shooter
    Color color;    // The color of the shooter

public:
    Shooter(double position_x, double position_y, double vx_=100, double height=30, double width=18, double head_radius=8, Color color_=COLOR(0, 255, 0))
    {
        // Shooter constructor
        color = color_;

        // body (represented by a rectangle)
        body = Rectangle(position_x, position_y, width, height);
        body.setColor(color);
        body.setFill(true);

        // head (represented by a circle)
        head = Circle(position_x, position_y - height/2. - head_radius, head_radius);
        head.setColor(color);
        head.setFill(true);

        // initial velocity
        vx = vx_;
    }

    Bullet shoot()
    {
        // shoot a bullet
        return Bullet(head.getX(), head.getY());
    }

    void move(double t, bool is_moving_left)
    {
        // move the shooter
        double vel = vx;
        if (is_moving_left)
        {
            vel = -vel;
        }

        double new_body_x = body.getX() + vel*t;
        double new_head_x = head.getX() + vel*t;

        if (vel < 0 && new_body_x < (0 + body.getWidth()/2.0)) // stop moving along X direction at left border (if pressed A)
        {
            new_body_x = 0 + body.getWidth()/2.0;
            new_head_x = 0 + body.getWidth()/2.0;
        }
        else if (vel > 0 && new_body_x > (WINDOW_X - body.getWidth()/2.0)) // stop moving along X direction at right border (if pressed D)
        {
            new_body_x = WINDOW_X - body.getWidth()/2.0;
            new_head_x = WINDOW_X - body.getWidth()/2.0;
        }

        body.moveTo(new_body_x, body.getY());
        head.moveTo(new_head_x, head.getY());
    }

    void center(){
        //moves the shooter to its starting position
        body.moveTo(SHOOTER_START_X, SHOOTER_START_Y);
        head.moveTo(SHOOTER_START_X, head.getY());
        return;
    }

    double get_head_center_x()
    {
        // return the x coordinate of the center of the head
        return head.getX();
    }

    double get_head_center_y()
    {
        // return the y coordinate of the center of the head
        return head.getY();
    }

    double get_head_radius()
    {
        // return the radius of the head
        return head.getRadius();
    }

    double get_body_center_x()
    {
        // return the x coordinate of the center of the body
        return body.getX();
    }

    double get_body_center_y()
    {
        // return the y coordinate of the center of the body
        return body.getY();
    }

    double get_body_width()
    {
        // return the width of the body
        return body.getWidth();
    }

    double get_body_height()
    {
        // return the height of the body
        return body.getHeight();
    }

};
