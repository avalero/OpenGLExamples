#include "square.h"
#include <GL/glu.h>

Square::Square(double _side, const array<double, 3> &_color, double _x_step, double _y_step):
    Figure{0,0,_x_step, _y_step, _color},
    side{_side}
{

}

void Square::drawGL() const
{
    glMatrixMode(GL_MODELVIEW);
    // save current ModelView Matrix
    glPushMatrix();
    glTranslated(x, y, 0);
    glColor3d(color.at(0), color.at(1), color.at(2));
    glBegin(GL_POLYGON);
    glVertex2d(-side/2, -side/2); //bottom left
    glVertex2d(-side/2, side/2); // top left
    glVertex2d(side/2, side/2); // top right
    glVertex2d(side/2, -side/2); // bottom right
    glEnd();
    // recover saved ModelView Matrix
    glPopMatrix();
}
