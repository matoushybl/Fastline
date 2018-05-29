//
// Created by Matouš Hýbl on 29/05/2018.
//

#ifndef FASTLINE_CALIBRATIONDATA_H
#define FASTLINE_CALIBRATIONDATA_H


#include <inttypes.h>

#define CALIBRATION_START 0

class CalibrationData {
public:
    static void loadLineSensorMinimums(uint16_t* minumums);
    static void loadLineSensorMaximums(uint16_t* maximums);

    static void saveLineSensorMinimums(uint16_t* minumums);
    static void saveLineSensorMaximums(uint16_t* maximums);
};


#endif //FASTLINE_CALIBRATIONDATA_H
