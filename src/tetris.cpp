#include "shapes/line.hpp"
#include "LedController.hpp"

Line line = Line();
LedController ledController(13, 11, 12, 1);

void inita()
{
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    ledController.setIntensity(15);
}

void update()
{
    line.update(ledController);
}

void draw()
{
    line.draw(ledController);
}