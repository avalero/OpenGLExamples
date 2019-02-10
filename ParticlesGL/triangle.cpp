#include "triangle.h"
#include <GL/glu.h>
#include <math.h>

Triangle::Triangle(double _side, const array<double, 3> &_color, double _x_step, double _y_step):
    Figure{0,0,_x_step, _y_step, _color},
    side{_side}
{
    // to avoid calculating every time

    h = sqrt(3)*side/2.0;
    half_h = h/2.0;
    half_side = side/2.0;

}

void Triangle::drawGL() const
{
    glMatrixMode(GL_MODELVIEW);
    // save current ModelView Matrix
    glPushMatrix();
    glTranslated(x, y, 0);
    glColor3d(color.at(0), color.at(1), color.at(2));
    glBegin(GL_POLYGON);
    glVertex2d(-half_side, -half_h); //bottom left
    glVertex2d(0, half_h); // top
    glVertex2d(half_side, -half_h); // bottom right
    glEnd();
    // recover saved ModelView Matrix
    glPopMatrix();
}
