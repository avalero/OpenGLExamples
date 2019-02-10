#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle: public Figure
{
public:
    Triangle(double _side, array<double, 3> const &  _color, double _x_step, double _y_step);

    void drawGL() const;

private:
    double side;

};

#endif // TRIANGLE_H
