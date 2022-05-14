#pragma once
#include <Arduino.h>
#include "dot.hpp"

class Shape
{
private:
public:
    Shape();
    enum Rotations
    {
        form1,
        form2,
        form3,
        form4
    };

    virtual void update();
    virtual void draw();
    virtual void moveRight();
    virtual void moveLeft();
    virtual void setForm(Rotations form);

    ~Shape();

protected:
    uint16_t speed = 100;
    Rotations form = Rotations::form1;
};