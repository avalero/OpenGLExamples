#ifndef BALL_H
#define BALL_H

#include "figure.h"

class Ball : public Figure
{
public:
    Ball();

    void drawGL();
    void step();
private:
    float angle;
    float angle_step;
};

#endif // BALL_H
