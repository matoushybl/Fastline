//
// Created by Matouš Hýbl on 29/05/2018.
//

#include "ADConverter.h"

ADConverter::ADConverter() {
    ADCSRA = (1 << ADEN) | 0b00000111; // prescaler;

}

uint16_t ADConverter::measure(uint8_t channel) {
    ADMUX = (1 << REFS0) | (channel & 0b00000111);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1<<ADSC)); // wait for the conversion

    return ADCW;
}
