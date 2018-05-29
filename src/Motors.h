//
// Created by Matouš Hýbl on 29/05/2018.
//

#ifndef FASTLINE_MOTORS_H
#define FASTLINE_MOTORS_H

#include <inttypes.h>
#include "Registers.h"

#define LeftEnable SPORTD.P6
#define LeftForward SPORTD.P2
#define LeftBackward SPORTD.P3

#define RightEnable SPORTD.P5
#define RightForward SPORTD.P4
#define RightBackward SPORTD.P7

class Motors {

public:
    Motors();
    void forward();
    void backward();
    void rotateLeft();
    void rotateRight();
    void turnLeft();
    void turnRight();
    void setLeftSpeed(uint8_t speed);
    void setRightSpeed(uint8_t speed);
    void setSpeed(uint8_t speed);
    void setSpeeds(uint8_t leftSpeed, uint8_t rightSpeed);

};


#endif //FASTLINE_MOTORS_H
