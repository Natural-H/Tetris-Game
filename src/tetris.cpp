#include "dot.hpp"
#include "shapes/line.hpp"
#include "LedController.hpp"

LedController matrix(13, 11, 12, 1);
LedController& Dot::matrix = matrix;
Line line = Line();

void inita()
{
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    matrix.setIntensity(15);
}

void update()
{
    matrix.setColumn(0, 2, 255);
    line.update();
}

void draw()
{
    line.draw();
}