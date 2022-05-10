#include "button.hpp"

button::button(byte pin) : pin(pin)
{
    Initialize();
}

byte button::getPin() { return pin; }

void button::Initialize()
{
    pinMode(pin, INPUT);
    updateState();
}

void button::updateState()
{
    byte newReading = digitalRead(pin);

    if (newReading != lastReading && newReading)
        lastDebonuceTime = millis();

    if (millis() - lastDebonuceTime > debonuceDelay)
        state = newReading;

    lastReading = newReading;
}

byte button::getState()
{
    updateState();
    return state;
}

bool button::isPressed()
{
    return getState();
}

button::~button() {}
