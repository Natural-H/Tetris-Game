#include "dot.hpp"

Dot::Dot() {}
Dot::Dot(byte x_position) : x(x_position) {}

void Dot::update(uint16_t speed)
{
    if (millis() - ulast > speed && !somethingDown())
    {
        isMoving = true;
        ulast = millis();
        y++;
    }
    else
        isMoving = false;
}

void Dot::draw()
{
    if (y <= 7)
    {
        matrix.setLed(0, x, y, true);
        if (isMoving)
            matrix.setLed(0, x, y - 1, false);
    }
}

void Dot::setPoint(uint8_t new_x, uint8_t new_y)
{
    setX(new_x);
    setY(new_y);
}

void Dot::setX(uint8_t new_x)
{
    matrix.setLed(0, getX(), getY(), false);
    x = new_x;
}

void Dot::setY(uint8_t new_y)
{
    matrix.setLed(0, getX(), getY(), false);
    y = new_y;
}

uint8_t Dot::getX() { return x; }
uint8_t Dot::getY() { return y; }

bool Dot::somethingDown()
{
    return (matrix.getRow(0, x) & (1 << (6 - y))) >> (6 - y) || y > 7;
}

Dot::~Dot() {}