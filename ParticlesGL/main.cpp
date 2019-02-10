#include <GL/glut.h>
#include <vector>
#include <array>
#include <iostream>

#include "triangle.h"
#include "circle.h"
#include "square.h"
#include "figure.h"

using namespace std;

array<double,3> randomColor(){
    array<double,3> color;
    color.at(0) = rand()%255 / 255.0;
    color.at(1) = rand()%255 / 255.0;
    color.at(2) = rand()%255 / 255.0;
    return color;
}

double randomStep(){
    double step = rand()%100/10000.0;
    return step;
}

double randomRadius(){
    double r = rand()%100/1000.0;
    return r;
}

double randomSide(){
    double s = rand()%100/1000.0;
    return s;
}

vector<Figure*> figures;



bool init()
{
    glClearColor(1, 1, 1, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    return true;
}

void renderScene(void) {

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT);

    for(auto figure:figures){
        figure->drawGL();
        figure->step();
    }

    glutSwapBuffers();
}

int main(int argc, char **argv) {

    srand(time(NULL));

    // create figures
    unsigned int aux{0};
    cout << "Cuantos círculos quieres? ";
    cin >> aux;

    for(unsigned int i{0}; i < aux; i++){
        figures.push_back(new Circle(randomRadius(),randomColor(),randomStep(), randomStep()));
    }

    cout << "Cuantos cuadrados quieres? ";
    cin >> aux;

    for(unsigned int i{0}; i < aux; i++){
        figures.push_back(new Square(randomSide(),randomColor(),randomStep(), randomStep()));
    }

    cout << "Cuantos triangulos quieres? ";
    cin >> aux;

    for(unsigned int i{0}; i < aux; i++){
        figures.push_back(new Triangle(randomSide(),randomColor(),randomStep(), randomStep()));
    }


    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,800);
    glutCreateWindow("ParticlesGL - GLUT Tutorial");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);

    init();

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
