#include <GL/glut.h>
#include <vector>

#include "ball.h"

Ball ball1{0.1, {1,0,0}};


bool init()
{
    glClearColor(1, 1, 1, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    return true;
}

void renderScene(void) {

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT);

    ball1.drawGL();
    ball1.step();

    glutSwapBuffers();
}

int main(int argc, char **argv) {

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,800);
    glutCreateWindow("Lighthouse3D- GLUT Tutorial");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);

    init();

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
