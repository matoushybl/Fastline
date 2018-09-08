//
// Created by Matouš Hýbl on 29/05/2018.
//

#include "Motors.h"
#include "Registers.h"
#include <avr/io.h>

Motors::Motors() {
    DDRD |= 0b11110000;
    DDRB |= (1 << PORTB0);
    TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM00) | (1 << WGM01);
    TCCR0B = (1 << CS01);
}

// left
//    OCR0B = 255;
//    SPORTB.P0 = 0;

// right
//    OCR0A = 0;
//    SPORTD.P7 = 1;

void Motors::forward(uint8_t leftSpeed, uint8_t rightSpeed) {
    // LEFT
    OCR0B = leftSpeed;
    Left = 0;

    // RIGHT
    OCR0A = 0xFF - rightSpeed;
    Right = 1;
}

void Motors::backward(uint8_t leftSpeed, uint8_t rightSpeed) {
    // LEFT
    OCR0B = 0xFF - leftSpeed;
    Left = 1;

    // RIGHT
    OCR0A = rightSpeed;
    Right = 0;
}

void Motors::rotateLeft(uint8_t leftSpeed, uint8_t rightSpeed) {
    // LEFT
    OCR0B = 0xff - leftSpeed;
    Left = 1;

    // RIGHT
    OCR0A = 0xFF - rightSpeed;
    Right = 1;
}

void Motors::rotateRight(uint8_t leftSpeed, uint8_t rightSpeed) {
    // LEFT
    OCR0B = leftSpeed;
    Left = 0;

    // RIGHT
    OCR0A = rightSpeed;
    Right = 0;
}

void Motors::turnLeft(uint8_t speed) {
    // LEFT
    OCR0B = 0;
    Left = 0;

    // RIGHT
    OCR0A = 0xFF - speed;
    Right = 1;
}

void Motors::turnRight(uint8_t speed) {
    // LEFT
    OCR0B = speed;
    Left = 0;

    // RIGHT
    OCR0A = 0xFF;
    Right = 1;
}

void Motors::stop() {
    OCR0B = 255;
    Left = 1;

    OCR0A = 255;
    Right = 1;
}
