#include <GL/glut.h>
#include <vector>

#include "ball.h"

Ball ball1{10,0,80};


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

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = GLfloat(width) / GLfloat(height);

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset the projection matrix
    if (width >= height) {
        // aspect >= 1, set the height from -1 to 1, with larger width
        gluOrtho2D(-100.0 * aspect, 100.0 * aspect, -100.0, 100.0);
    } else {
        // aspect < 1, set the width to -1 to 1, with larger height
        gluOrtho2D(-100.0, 100.0, -100.0 / aspect, 100.0 / aspect);
    }
}

int main(int argc, char **argv) {

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(800,800);
    glutCreateWindow("Lighthouse3D- GLUT Tutorial");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(reshape);
    init();

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
