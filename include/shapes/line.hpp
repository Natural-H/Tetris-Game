#pragma once
#include "shape.hpp"

class Line : public Shape
{
private:
    Dot dots[2];
public:
    void update(LedController&) override;
    void draw(LedController&) override;
    void moveRight(LedController&) override;
    void moveLeft(LedController&) override;
    void setForm(Rotations form, LedController&) override;

    Line();
    ~Line();
};