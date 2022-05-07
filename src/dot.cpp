#include "dot.hpp"

Dot::Dot() {}
Dot::Dot(byte x_position) : x(x_position) {}

void Dot::update(uint16_t speed, LedController &matrix)
{
    if (millis() - ulast > speed && !somethingDown(matrix))
    {
        isMoving = true;
        ulast = millis();
        y++;
    }
    else
        isMoving = false;
}

void Dot::draw(LedController &matrix)
{
    if (y <= 7)
    {
        matrix.setLed(0, x, y, true);
        if (isMoving)
            matrix.setLed(0, x, y - 1, false);
    }
}

void Dot::setPoint(uint8_t new_x, uint8_t new_y, LedController& matrix)
{
    setX(new_x, matrix);
    setY(new_y, matrix);
}

void Dot::setX(uint8_t new_x, LedController& matrix)
{
    matrix.setLed(0, getX(), getY(), false);
    x = new_x;
}

void Dot::setY(uint8_t new_y, LedController& matrix)
{
    matrix.setLed(0, getX(), getY(), false);
    y = new_y;
}

uint8_t Dot::getX() { return x; }
uint8_t Dot::getY() { return y; }

bool Dot::somethingDown(LedController &matrix)
{
    return (matrix.getRow(0, x) & (1 << (6 - y))) >> (6 - y) || y > 7;
}

Dot::~Dot() {}