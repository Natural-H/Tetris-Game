#pragma once
#include <Arduino.h>
#include "LedController.hpp"

class Dot
{
private:
    int8_t x, y = -1;
    unsigned long ulast = 0;
    bool isMoving = false;

public:
    static LedController &matrix;
    Dot(void);
    Dot(byte);

    void update(uint16_t);
    void draw();
    void setPoint(uint8_t, uint8_t);
    void setX(uint8_t);
    void setY(uint8_t);

    bool somethingDown();
    uint8_t getX();
    uint8_t getY();

    ~Dot();
};