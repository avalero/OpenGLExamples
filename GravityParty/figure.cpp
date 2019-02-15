#include "figure.h"
#include <iostream>

using namespace std;

Figure::Figure(float _x, float _y, float _sx, float _sy, float _ax, float _ay, array<float,3> _color):
    x{_x},
    y{_y},
    sx{_sx},
    sy{_sy},
    ax{_ax},
    ay{_ay},
    color{_color}
{
    prev_t = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
}

void Figure::step()
{
    double t = getElapsedTime()/1000.0;
    cout << t << endl;
    x = x + sx*t + ax*t*t/2.0;
    y = y + sy*t + ay*t*t/2.0;

    sx = sx + ax*t;
    sy = sy + ay*t;

    if(y < -100){
        y = -100;
        sy = -sy;
    }

    if(y > 100){
        y = 100;
        sy = -sy;
    }

    if(x < -100){
        x = -100;
        sx = -sx;
    }

    if(x > 100){
        x = 100;
        sx = -sx;
    }
}

long int Figure::getElapsedTime()
{
    milliseconds ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    milliseconds elapsed = ms - prev_t;
    prev_t = ms;
    return elapsed.count();
}
