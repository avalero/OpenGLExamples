#include "circle.h"
#include <GL/glut.h>

#include <iostream>
#include <math.h>

using namespace std;

Circle::Circle(double _radius, array<double, 3> const & _color, double _x_step, double _y_step):
    Figure{0,0,_x_step, _y_step, _color},
    radius{_radius}
{

}

void Circle::drawGL() const
{
    glMatrixMode(GL_MODELVIEW);
    // save current ModelView Matrix
    glPushMatrix();
    glTranslatef(x, y, 0);
    glColor3f(color.at(0), color.at(1), color.at(2));
    glBegin(GL_POLYGON);
    const float twoPI{2*3.14f};
    for(float i{0}; i < twoPI; i+=0.3f){
        float x_ball = radius*cos(i);
        float y_ball = radius*sin(i);
        glVertex2f(x_ball,y_ball);
    }
    glEnd();
    // recover saved ModelView Matrix
    glPopMatrix();
}
