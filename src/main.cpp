#include <Arduino.h>

void inita();
void update();
void draw();

void setup()
{
    Serial.begin(9600);
    inita();
}

void loop()
{
    update();
    draw();
}