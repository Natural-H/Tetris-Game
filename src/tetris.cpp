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
    Dot::matrix.setIntensity(15);
    a.push_back(Line());
}

void update()
{
    // if (millis() - last > 2000)
    // {
    //     a.push_back(Line());
    //     last = millis();
    // }
    Serial.println("Nothing down");

    for (int i = 0; i < a.size(); i++)
    {
        a[i].update();
        if (!a[i].isActive())
            a.push_back(Line());
    }
    // line.update();
}

void draw()
{
    for (int i = 0; i < a.size(); i++)
        a[i].draw();
    // line.draw();
}