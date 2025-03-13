//=====[Libraries]=============================================================

#include "gas_sensor.h"
#include "mbed.h"
#include "arm_book_lib.h"
#include "alarm.h"
#include "display.h"
#include "timer.h"
#include "user_interface.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

// runs all initializations
void toasterAlertSystemInit() {
    InputsInit();
    outputsInit();
    gasSensorInit();
    temperatureSensorInit();
    timerInit();
    alarmSystemInit();
}

// runs all updates
void toasterAlertSystemUpdate() {
    gasSensorUpdate();
    temperatureSensorUpdate();
    user_InterfaceUpdate();
    timerUpdate();
    alarmUpdate(); 
}
