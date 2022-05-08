#include "dot.hpp"
#include "shapes/line.hpp"
#include "LedController.hpp"

LedController Dot::matrix = LedController(13, 11, 12, 1);
Line line = Line();

void inita()
{
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    Dot::matrix.setIntensity(15);
}

void update()
{
    line.update();
}

void draw()
{
    line.draw();
}