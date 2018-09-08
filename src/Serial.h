//
// Created by Matous Hybl on 07/09/2018.
//

#ifndef FASTLINE_SERIAL_H
#define FASTLINE_SERIAL_H

#include <inttypes.h>

class Serial {
public:
    Serial();

    void write(uint8_t data);
};


#endif //FASTLINE_SERIAL_H
