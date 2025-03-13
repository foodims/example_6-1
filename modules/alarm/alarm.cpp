
//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "temperature_sensor.h"
#include "gas_sensor.h"
#include "user_interface.h"


//=====[Declaration of private defines]========================================

//defines heat threshold of 35 celcius(human touch), used for testing purposes 
#define HEAT_LEVEL     35

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//variables used to store data throughout the system
bool emergency = false;
bool gasDetected = false;
bool overTemp = false;

//=====[Declarations (prototypes) of private functions]========================



//=====[Implementations of public functions]===================================

//initializes alarm system outputs
void alarmSystemInit() {
gasDetected = false;
overTemp = false;
emergency = false; 
}

//controls alarm state based on sensor readings
//emergency variable stores alarm output, to be used in other modules
void alarmUpdate() {
    float tempReading = temperatureSensorReadCelsius();
    gasDetected = gasSensorRead();

    if (tempReading > HEAT_LEVEL || gasDetected) {
        emergency = true;

    } else {
        emergency = false;
    }
}

