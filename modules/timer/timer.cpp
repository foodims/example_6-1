
//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "timer.h"
#include "user_interface.h"
#include "display.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

Timer countdownTimer;
int timeRemaining = 0;
chrono::seconds lastUpdateTime = 0s;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

//intializes timer
void timerInit() {
countdownTimer.stop();
countdownTimer.reset();
timeRemaining = 0;
}

// defines timer values and starts timer based on toastLevel 
void timerStart() {
if (Dark_Level() == "light") {
    timeRemaining = 10;
}
else if (Dark_Level() == "medium") {
    timeRemaining = 20;
}
else if (Dark_Level() == "dark") {
    timeRemaining = 30;
}
else {
    timeRemaining = 0;
}
countdownTimer.start();
lastUpdateTime = chrono::duration_cast<chrono::seconds>(countdownTimer.elapsed_time());
}

// updates timer every second
void timerUpdate() {
if (timeRemaining > 0) {
    chrono::seconds elapsed = chrono::duration_cast<chrono::seconds>(countdownTimer.elapsed_time());
    if (elapsed > lastUpdateTime) {
    timeRemaining--;
    lastUpdateTime = elapsed;
    }
}
}


// checks if the timer is done
bool isTimerDone() {
    return timeRemaining <= 0;
}

//returns remaining time
int getTimeRemaining() {
    return timeRemaining;
}