#pragma once
#include <Arduino.h>

class button
{
private:
    byte pin;
    byte state;
    byte lastReading;

    unsigned long lastDebonuceTime = 0;
    unsigned long debonuceDelay = 50;

public:
    button(byte);
    ~button();

    byte getPin();
    byte getState();

    void Initialize();
    void updateState();

    bool isPressed();
};