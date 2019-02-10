#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure
{
public:
    Square(double _side, array<double, 3> const &  _color, double _x_step, double _y_step);
    void drawGL() const;

private:
    double side;
};

#endif // SQUARE_H
