#ifndef BALL_H
#define BALL_H

#include "figure.h"

class Ball : public Figure
{
public:
    Ball(float _radius,
         float x0,
         float y0,
         float sx0 = 0,
         float sy0 = 0,
         float ax = 0,
         float ay = -9.8f,
         array<float,3> color = {1,0,0});

    void drawGL();
private:
    float radius;
};

#endif // BALL_H
