
//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "temperature_sensor.h"
#include "gas_sensor.h"
#include "user_interface.h"


//=====[Declaration of private defines]========================================

//defines heat threshold of 30 celcius(human touch)
#define HEAT_LEVEL     40

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

bool alarmOn = false;
bool gasDetected = false;
bool overTemp = false;

//=====[Declarations (prototypes) of private functions]========================

void alarmState(bool state);

//=====[Implementations of public functions]===================================

//initializes alarm system outputs
void alarmSystemInit() {
gasDetected = false;
overTemp = false;
alarmOn = false;
}

//controls alarm state based on sensor readings
void alarmUpdate() {
    float tempReading = temperatureSensorReadCelsius();
    gasDetected = gasSensorRead();

    if (tempReading > HEAT_LEVEL || gasDetected) {
        alarmState(true);
    } else {
        alarmState(false);
    }
}

void alarmState(bool state) {
    if (state) {
       alarmOn = true;
    } 
    else {
        alarmOn = false;
    }
}
