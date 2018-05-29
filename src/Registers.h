//
// Created by Matouš Hýbl on 29/05/2018.
//

#ifndef FASTLINE_REGISTERS_H
#define FASTLINE_REGISTERS_H

#include <inttypes.h>

typedef struct {
    uint8_t P0 : 1;
    uint8_t P1 : 1;
    uint8_t P2 : 1;
    uint8_t P3 : 1;
    uint8_t P4 : 1;
    uint8_t P5 : 1;
    uint8_t P6 : 1;
    uint8_t P7 : 1;
} PORT;

#define SPINB (*(volatile PORT *) 0x23)
#define SDDRB (*(volatile PORT *) 0x24)
#define SPORTB (*(volatile PORT *) 0x25)

#define SPINC (*(volatile PORT *) 0x26)
#define SDDRC (*(volatile PORT *) 0x27)
#define SPORTC (*(volatile PORT *) 0x28)

#define SPIND (*(volatile PORT *) 0x29)
#define SDDRD (*(volatile PORT *) 0x2A)
#define SPORTD (*(volatile PORT *) 0x2B)

class Registers {

};


#endif //FASTLINE_REGISTERS_H
