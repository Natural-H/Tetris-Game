#pragma once
#include "shape.hpp"

class Line : public Shape
{
private:
    Dot dots[2];
public:
    void update() override;
    void draw() override;
    void moveRight() override;
    void moveLeft() override;
    void setForm(Rotations form) override;

    Line();
    ~Line();
};