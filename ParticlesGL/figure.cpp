#include "figure.h"

Figure::Figure(double _x, double _y, double _x_step, double _y_step, array<double, 3> const & _color):
    x{_x},
    y{_y},
    x_step{_x_step},
    y_step{_y_step},
    color{_color}
{

}

void Figure::step()
{
    // move object
    x += x_step;
    y += y_step;

    // check if object is out of bounds
    if(x >= 1){
        x = 1;
        x_step = -x_step;
    }

    if(x <= -1){
        x = -1;
        x_step = -x_step;
    }

    if(y >= 1){
        y = 1;
        y_step = -y_step;
    }

    if(y <= -1){
        y = -1;
        y_step = -y_step;
    }

}
