#include "shapes/line.hpp"

Line::Line()
{
    dots[0] = Dot(4);
    dots[1] = Dot(5);
}

void Line::update(LedController &matrix)
{
    if (digitalRead(3) && dots[0].getX() < 8)
        setForm(Rotations::form2, matrix);

    if (digitalRead(2) && dots[0].getX() >= 0)
        setForm(Rotations::form1, matrix);

    for (size_t i = 0; i < sizeof(dots) / sizeof(dots[0]); i++)
        dots[i].update(speed, matrix);
}

void Line::draw(LedController &matrix)
{
    for (size_t i = 0; i < sizeof(dots) / sizeof(dots[0]); i++)
        dots[i].draw(matrix);
}

void Line::moveLeft(LedController &matrix)
{
    dots[0].setX(dots[0].getX() - 1, matrix);
}

void Line::moveRight(LedController &matrix)
{
    dots[0].setX(dots[0].getX() + 1, matrix);
}

void Line::setForm(Rotations form, LedController& matrix)
{
    this->form = form;

    switch (form)
    {
    case Rotations::form1:
        dots[1].setPoint(dots[0].getX() + 1, dots[0].getY(), matrix);
        break;
    case Rotations::form2:
        dots[1].setPoint(dots[0].getX(), dots[0].getY() + 1, matrix);
        break;
    case Rotations::form3:
        dots[1].setPoint(dots[0].getX() - 1, dots[0].getY(), matrix);
        break;
    case Rotations::form4:
        dots[1].setPoint(dots[0].getX(), dots[0].getY() - 1, matrix);
        break;
    }
}

Line::~Line() {}