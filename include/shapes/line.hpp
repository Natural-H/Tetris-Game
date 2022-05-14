#pragma once
#include "shape.hpp"
#include "button.hpp"

class Line : public Shape
{
public:
    Dot dots[2];
    void update() override;
    void draw() override;
    void moveRight() override;
    void moveLeft() override;
    void setForm(Rotations form) override;

    bool isActive();

    Dot getDowner();

    Line();
    Line(uint8_t);
    ~Line();

private:
    button formButton = 2;
    bool active = true;
    bool last = false;
};