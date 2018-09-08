//
// Created by Matouš Hýbl on 29/05/2018.
//

#ifndef FASTLINE_MOTORS_H
#define FASTLINE_MOTORS_H

#include <inttypes.h>
#include "Registers.h"

#define Left SPORTB.P0

#define Right SPORTD.P7

class Motors {

public:
    Motors();
    void forward(uint8_t leftSpeed = 0xff, uint8_t rightSpeed = 0xff);
    void backward(uint8_t leftSpeed = 0xff, uint8_t rightSpeed = 0xff);
    void rotateLeft(uint8_t leftSpeed = 0xff, uint8_t rightSpeed = 0xff);
    void rotateRight(uint8_t leftSpeed = 0xff, uint8_t rightSpeed = 0xff);
    void turnLeft(uint8_t speed = 0xff);
    void turnRight(uint8_t speed = 0xff);
    void stop();
};


#endif //FASTLINE_MOTORS_H
