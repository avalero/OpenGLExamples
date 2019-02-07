#include "ball.h"
#include <GL/glut.h>

#include <iostream>

using namespace std;

Ball::Ball():
    angle{0},
    angle_step{0.1}
{

}

void Ball::drawGL()
{
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    cout << angle << endl;
    glBegin(GL_TRIANGLES);
    glVertex3f(-2.0f,-2.0f, 0.0f);
    glVertex3f( 2.0f, 0.0f, 0.0);
    glVertex3f( 0.0f, 2.0f, 0.0);
    glEnd();

}

void Ball::step()
{
    angle += angle_step;

}
