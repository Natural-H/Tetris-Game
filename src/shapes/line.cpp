#include "shapes/line.hpp"

Line::Line()
{
    dots[0] = Dot(4);
    dots[1] = Dot(5);
}

Line::Line(uint8_t x)
{
    dots[0] = Dot(x);
    dots[1] = Dot(x + 1);
}

Dot Line::getDowner()
{
    return min(dots[0].getY(), dots[1].getY()) == dots[0].getY() ? dots[0] : dots[1]; // I know, this is an awful implementation
}

void Line::update()
{
    bool newState = formButton.isPressed();
    active = !getDowner().somethingDown();

    for (size_t i = 0; i < sizeof(dots) / sizeof(dots[0]); i++)
        dots[i].update(speed);

    if (active)
    {
        if (newState != last && newState)
        // setForm((Rotations)(form + 1) > Rotations::form4 ? Rotations::form1 : (Rotations)(form + 1));
        {
            moveRight();
            Serial.println("a");
        }
    }

    last = newState;
}

bool Line::isActive()
{
    return active;
}

void Line::draw()
{
    for (size_t i = 0; i < sizeof(dots) / sizeof(dots[0]); i++)
        dots[i].draw();
}

void Line::moveLeft()
{
    dots[0].setX(dots[0].getX() - 1);
}

void Line::moveRight()
{
    dots[0].setX(dots[0].getX() + 1);
    dots[1].setX(dots[0].getX() + 1);
}

void Line::setForm(Rotations form)
{
    this->form = form;

    switch (form)
    {
    case Rotations::form1:
        dots[1].setPoint(dots[0].getX() + 1, dots[0].getY());
        break;
    case Rotations::form2:
        dots[1].setPoint(dots[0].getX(), dots[0].getY() - 1);
        break;
    case Rotations::form3:
        dots[1].setPoint(dots[0].getX() + 1, dots[0].getY());
        break;
    case Rotations::form4:
        dots[1].setPoint(dots[0].getX(), dots[0].getY() - 1);
        break;
    }
}

Line::~Line() {}