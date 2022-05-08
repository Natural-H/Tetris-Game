#include "vector.hpp"
#include "dot.hpp"
#include "shapes/line.hpp"
#include "LedController.hpp"

LedController Dot::matrix = LedController(13, 11, 12, 1);
vector<Line> a;
unsigned long last = 0;
// Line line = Line();

void inita()
{
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    Dot::matrix.setIntensity(15);
    a.push_back(Line());
}

void update()
{
    if (millis() - last > 300)
    {
        a.push_back(Line());
        last = millis();
    }

    for (int i = 0; i < a.size() - 1; i++)
        a[i].update();
    // line.update();
}

void draw()
{
    for (int i = 0; i < a.size() - 1; i++)
        a[i].draw();
    // line.draw();
}