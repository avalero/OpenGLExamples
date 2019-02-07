#ifndef BALL_H
#define BALL_H

#include "figure.h"

class Ball : public Figure
{
public:
    Ball(float _radius, array<float, 3> color);

    void drawGL();
    void step();
private:
    float radius;
};

#endif // BALL_H
