#pragma once
#include "shape.hpp"
#include "button.hpp"

class Line : public Shape
{
private:
    Dot dots[2];
    button formButton = 2;
    bool active = true;

public:
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
};