//
// Created by Matous Hybl on 07/09/2018.
//

#include "Serial.h"
#include "avr/io.h"

Serial::Serial() {
    // 115200 8N1
    UBRR0L = 8;
    UCSR0A = 0;
    UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
}

void Serial::write(uint8_t data) {
    while ((UCSR0A & (1 << UDRE0)) == 0);
    UDR0 = data;
}
