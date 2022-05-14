#pragma once
#include "shape.hpp"
#include "button.hpp"

class Line : public Shape
{
public:
    Dot dots[2];
    static button rightButton;
    static button leftButton;

private:
    bool active = true;
    bool lastR = false;
    bool lastL = false;

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