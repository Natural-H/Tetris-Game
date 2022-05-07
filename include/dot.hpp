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
    Dot(void);
    Dot(byte);

    void update(uint16_t, LedController&);
    void draw(LedController&);
    void setPoint(uint8_t, uint8_t, LedController&);
    void setX(uint8_t, LedController&);
    void setY(uint8_t, LedController&);

    bool somethingDown(LedController&);
    uint8_t getX();
    uint8_t getY();

    ~Dot();
};