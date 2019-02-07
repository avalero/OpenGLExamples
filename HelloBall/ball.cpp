#include "ball.h"
#include <GL/glut.h>

#include <iostream>
#include <math.h>

using namespace std;

Ball::Ball(float _radius, array<float,3> color):
    Figure{0,0,color},
    radius{_radius}
{
    x_step = 0.003;
    y_step = 0.003;

}

void Ball::drawGL()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(x, y, 0);
    glColor3f(color.at(0), color.at(1), color.at(2));
    glBegin(GL_POLYGON);
    for(float i{0}; i< 2*3.14; i+=0.3){
        float x_ball = radius*cos(i);
        float y_ball = radius*sin(i);
        glVertex2f(x_ball,y_ball);
    }
    glEnd();
}

void Ball::step()
{
    x += x_step;
    y += y_step;
}
