#ifndef FIGURE_H
#define FIGURE_H

#include <array>

using namespace std;

class Figure
{
public:
    Figure(double _x, double _y, double _x_step, double _y_step, array<double, 3> const & _color);
    virtual ~Figure()
    {

    }

    virtual void drawGL() const = 0;
    virtual void step();

protected:
    double x,y;
    double x_step, y_step;
    array<double,3> color;
};

#endif // FIGURE_H
