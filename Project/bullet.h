/*
* MODIFIED BY: ASHWIN ABRAHAM
*/
#include <simplecpp>

class Bullet
{
private:
    Rectangle rect; // the rectangle representing the bullet
    double vy; // velocity in y direction

public:
    Bullet(double center_x, double center_y, double width=10, double height=10, double vy_=400, Color color=COLOR(255, 0, 0)) {
        // Bullet constructor
        rect = Rectangle(center_x, center_y, width, height);
        rect.setColor(color);
        rect.setFill(true);
        vy = vy_;
    }

    bool nextStep(double t)
    {
        // move the bullet
        double new_y = rect.getY() - vy*t;
        if(new_y < (0-rect.getHeight()/2.0))   // out of canvas, so delete it
        {
            return false;
        }
        rect.moveTo(rect.getX(), new_y);
        return true;
    }

    double get_width()
    {
        // return the width of the bullet
        return rect.getWidth();
    }

    double get_height()
    {
        // return the height of the bullet
        return rect.getHeight();
    }

    double get_center_x()
    {
        // return the x coordinate of the center of the bullet
        return rect.getX();
    }

    double get_center_y()
    {
        // return the y coordinate of the center of the bullet
        return rect.getY();
    }

};
