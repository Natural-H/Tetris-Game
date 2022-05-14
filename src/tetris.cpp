#include "vector.hpp"
#include "dot.hpp"
#include "shapes/line.hpp"
#include "LedController.hpp"

LedController Dot::matrix = LedController(13, 11, 12, 1);
vector<Line> a;
Line *lastActive;
unsigned long last = 0;
// Line line = Line();

void inita()
{
    Dot::matrix.setIntensity(15);
    a.push_back(Line());
    lastActive = &a[0];
}

void update()
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i].update();
        if (!lastActive->isActive())
        {
            if (lastActive->dots[0].getY() == 0 && lastActive->dots[1].getY() == 0)
            {
                Serial.println("Stuck");
                break;
            }
            a.push_back(Line());
            lastActive = &a[i + 1]; // Using a.size() do bugs apparently
        }
    }
    // line.update();
}

void draw()
{
    for (int i = 0; i < a.size(); i++)
        a[i].draw();
    // line.draw();
}