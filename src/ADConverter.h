//
// Created by Matouš Hýbl on 29/05/2018.
//

#ifndef FASTLINE_ADC_H
#define FASTLINE_ADC_H

#include <avr/io.h>
#include <inttypes.h>

class ADConverter {

public:
    ADConverter();

    uint16_t measure(uint8_t channel);

};


#endif //FASTLINE_ADC_H
