#ifndef FIGURE_H
#define FIGURE_H

#include <array>

using namespace std;

class Figure
{
public:
    Figure(float _x, float _y, array<float,3> _color);
    virtual ~Figure()
    {

    }

    virtual void drawGL() = 0;
    virtual void step() = 0;

protected:
    float x,y;
    double x_step, y_step;
    array<float,3> color;
};

#endif // FIGURE_H
