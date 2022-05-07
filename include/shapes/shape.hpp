#pragma once
#include <Arduino.h>
#include "dot.hpp"

class Shape
{
private:
public:
    Shape();
    enum class Rotations
    {
        form1,
        form2,
        form3,
        form4
    };

    virtual void update(LedController&);
    virtual void draw(LedController&);
    virtual void moveRight(LedController&);
    virtual void moveLeft(LedController&);
    virtual void setForm(Rotations form, LedController&);

    ~Shape();

protected:
    uint16_t speed = 100;
    Rotations form = Rotations::form1;
};