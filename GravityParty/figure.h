#ifndef FIGURE_H
#define FIGURE_H

#include <array>
#include <chrono>

// ...

using namespace std::chrono;


using namespace std;

class Figure
{
public:
    Figure(float _x, float _y, float _sx, float _sy, float _ax, float _ay, array<float,3> _color);
    virtual ~Figure()
    {

    }

    virtual void drawGL() = 0;
    virtual void step();

protected:
    float x,y; //position
    float sx, sy; //speed
    float ax, ay; //accel
    array<float,3> color;

    long int getElapsedTime();

private:
    milliseconds prev_t;
};

#endif // FIGURE_H
