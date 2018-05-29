//
// Created by Matouš Hýbl on 29/05/2018.
//

#include "Motors.h"
#include "Registers.h"
#include <avr/io.h>

Motors::Motors() {
    DDRD |= 0b11111100;
    TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM00) | (1 << WGM01);
    TCCR0B = (1 << CS01);
}

void Motors::forward() {
    LeftForward = 1;
    RightForward = 1;
    LeftBackward = 0;
    RightBackward = 0;
}

void Motors::backward() {
    LeftForward = 0;
    RightForward = 0;
    LeftBackward = 1;
    RightBackward = 1;
}

void Motors::rotateLeft() {
    LeftForward = 0;
    RightForward = 1;
    LeftBackward = 1;
    RightBackward = 0;
}

void Motors::rotateRight() {
    LeftForward = 1;
    RightForward = 0;
    LeftBackward = 0;
    RightBackward = 1;
}

void Motors::turnLeft() {
    LeftForward = 0;
    RightForward = 1;
    LeftBackward = 0;
    RightBackward = 0;
}

void Motors::turnRight() {
    LeftForward = 1;
    RightForward = 0;
    LeftBackward = 0;
    RightBackward = 0;
}

void Motors::setLeftSpeed(uint8_t speed) {
    OCR0A = speed;
}

void Motors::setRightSpeed(uint8_t speed) {
    OCR0B = speed;
}

void Motors::setSpeed(uint8_t speed) {
    setSpeeds(speed, speed);
}

void Motors::setSpeeds(uint8_t leftSpeed, uint8_t rightSpeed) {
    setLeftSpeed(leftSpeed);
    setRightSpeed(rightSpeed);
}
