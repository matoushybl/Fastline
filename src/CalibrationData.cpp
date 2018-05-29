//
// Created by Matouš Hýbl on 29/05/2018.
//

#include "CalibrationData.h"
#include <avr/eeprom.h>

void CalibrationData::loadLineSensorMinimums(uint16_t *minumums) {
    for (int i = 0; i < 5; ++i) {
        minumums[i] = eeprom_read_word((uint16_t *)(CALIBRATION_START + 2 * i));
    }
}

void CalibrationData::loadLineSensorMaximums(uint16_t *maximums) {
    for (int i = 0; i < 5; ++i) {
        maximums[i] = eeprom_read_word((uint16_t *)(CALIBRATION_START + 10 + 2 * i));
    }
}

void CalibrationData::saveLineSensorMinimums(uint16_t *minumums) {
    for (int i = 0; i < 5; ++i) {
        eeprom_update_word((uint16_t *)(CALIBRATION_START + 2 * i), minumums[i]);
    }
}

void CalibrationData::saveLineSensorMaximums(uint16_t *maximums) {
    for (int i = 0; i < 5; ++i) {
        eeprom_update_word((uint16_t *)(CALIBRATION_START + 10 + 2 * i), maximums[i]);
    }
}
