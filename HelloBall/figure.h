#ifndef FIGURE_H
#define FIGURE_H


class Figure
{
public:
    Figure();
    virtual ~Figure()
    {

    }

    virtual void drawGL() = 0;
    virtual void step() = 0;
};

#endif // FIGURE_H
