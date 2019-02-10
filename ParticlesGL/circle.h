#ifndef BALL_H
#define BALL_H

#include "figure.h"

class Circle : public Figure
{
public:
    Circle(double _radius, const array<double, 3> &color, double _x_step, double _y_step);

    void drawGL() const;
private:
    double radius;
};

#endif // BALL_H
