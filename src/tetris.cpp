#include "vector.hpp"
#include "dot.hpp"
#include "shapes/line.hpp"
#include "LedController.hpp"

LedController Dot::matrix = LedController(13, 11, 12, 1);
vector<Line> a;
// Line line = Line();

void inita()
{
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    Dot::matrix.setIntensity(15);

    for (size_t i = 0; i < 5; i++)
        a.push_back(Line(i));
}

void update()
{
    for (size_t i = 0; i < 10; i++)
        a[i].update();
    // line.update();
}

void draw()
{
    for (size_t i = 0; i < 10; i++)
        a[i].draw();
    // line.draw();
}