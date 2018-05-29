#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include "Motors.h"
#include "ADConverter.h"
#include "CalibrationData.h"

#define LED SPORTB.P5

/**
Left enable D4 - PD6
Left A D3 - PD2
Left B D2 - PD3

Right enable D7 - PD5
Right A D4 - PD4
Right B D7 - PD7
**/
Motors motors;
ADConverter adc;

float normalize(uint16_t value, uint16_t min, uint16_t max) {
    float normalized = (value - min) / ((float) (max - min));
    if (normalized < 0) {
        return 0;
    } else if (normalized > 1) {
        return 1;
    } else {
        return normalized;
    }
}

uint8_t minmax(int16_t value) {
    if(value < 0) {
        return 0;
    }
    if (value > 255) {
        return 255;
    }
    return (uint8_t) value;
}

void calibrateMinimums() {
    uint16_t mins[5];
    for (int i = 0; i < 5; ++i) {
        mins[i] = adc.measure(i);
        _delay_ms(20);
    }
    CalibrationData::saveLineSensorMinimums(mins);

    LED = 1;
}

void calibrateMaximums() {
    uint16_t maxs[5];
    for (int i = 0; i < 5; ++i) {
        maxs[i] = adc.measure(i);
        _delay_ms(20);
    }
    CalibrationData::saveLineSensorMaximums(maxs);

    LED = 1;
}

int main(void) {
    DDRB = 0xFF;

    uint16_t minimums[5];
    uint16_t maximums[5];

    CalibrationData::loadLineSensorMinimums(minimums);
    CalibrationData::loadLineSensorMaximums(maximums);

    motors.setSpeed(255);

    motors.forward();

    int8_t lastDeviation = 0;
    int8_t sumation = 0;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    for(;;) {
        float weightedSum = 0;
        float sensorSum = 0;
        for(uint8_t i = 0; i < 5; i++) {
            float sensor = normalize(adc.measure(i), minimums[i], maximums[i]);
            weightedSum += sensor * i * 10;
            sensorSum += sensor;
        }

        int8_t position = (uint8_t) (weightedSum / sensorSum) - 20;
        int8_t deviation = -position;
        int16_t action = 5 * deviation;// + 2 * (deviation - lastDeviation) + 0.5 * sumation;

        motors.setSpeeds(minmax(150 + action), minmax(150 - action));

        sumation += deviation;
        lastDeviation = deviation;
    }
#pragma clang diagnostic pop
}

ISR(USART_RX_vect) {

}
