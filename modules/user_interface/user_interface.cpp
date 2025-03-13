//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "user_interface.h"
#include <string>
#include <type_traits>
#include "alarm.h"
#include "display.h"
#include "timer.h"
#include "gas_sensor.h"
#include "temperature_sensor.h"

//=====[Declaration of private defines]========================================

#define SYSTEM_TIME_INCREMENT 10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn in_Switch(D13);
DigitalIn on_Switch(D15);

AnalogIn Potentiometer(A1);

DigitalOut green_LED(D14);
DigitalOut red_LED(D12);
DigitalOut alarmBuzzer(PE_10);

UnbufferedSerial uartUsb( USBTX, USBRX, 115200 );

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

bool displayTime = false;
bool toasterOn = false;
bool displayCheck = false;
const float light = 0.33;
const float dark = 0.66;

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

// button configurations and initializations 
void InputsInit() {
in_Switch.mode(PullDown);
on_Switch.mode(PullDown);
}

// output configurations
void outputsInit() {
    green_LED = OFF;
    red_LED = OFF;
    alarmBuzzer = OFF;
}

// determines if food is in toaster or if toaster is turned on
// displays necessary messages on serial moniter
// changes LED and buzzer output depending on user switch inputs
void Food_In() {
if (in_Switch && !on_Switch) {
    toasterOn = false;
    green_LED = OFF;
    red_LED = ON;
    alarmBuzzer = ON;
    uartUsb.write("Food is in toaster, please press start to begin toasting\r\n", 60);
    uartUsb.write("\r\n", 2);
    }


else if (in_Switch && on_Switch) {
    toasterOn = true;
    green_LED = ON;
    red_LED = OFF;
    alarmBuzzer = OFF;
    uartUsb.write("Food has been inserted in toaster and toaster is ON\r\n", 51);
    uartUsb.write("\r\n", 2);

}

else if (!in_Switch && on_Switch) {
    toasterOn = false;
    green_LED = OFF;
    red_LED = ON;
    alarmBuzzer = ON;
    uartUsb.write("Toaster is on, but not food is occupying it. Please enter food.\r\n", 70);
    uartUsb.write("\r\n", 2);
}
}




// determines desired darkness level of toast 
// corresponds with timer
const char * Dark_Level() {   
if (!toasterOn) {
    return "N/A"; 
}

float levelselect = Potentiometer.read();
    if (levelselect < light) {
        return "light"; 
    }
    else if (levelselect > dark) {
        return "dark";   
    }
    else {
        return "medium"; 
    }
}

//displays the selected toast level on LCD
//displays the time remianing
//displays alarm state (danger/safe)
void displayChange() {
   
    displayInit();
    displayCharPositionWrite (0,0);
    displayStringWrite("Level:");

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Time:" );



if (timeRemaining > 0) {
    char buffer[6];
    displayCharPositionWrite(6,1);
    sprintf(buffer, "%d", timeRemaining);
    displayStringWrite(buffer);
    }

if (toasterOn) {
    displayCharPositionWrite( 7,0 );
    if (Dark_Level() == "light") {
        displayStringWrite("Light");
}
    if (Dark_Level() == "medium") {
        displayStringWrite("Medium");
}
    if (Dark_Level() == "dark") {
        displayStringWrite("Dark");
}   
}

displayCheck = true;
if (emergency == true && displayCheck){
    displayCharPositionWrite ( 10,1 );
    displayStringWrite( "DANGER" );
}
else if (emergency == false && displayCheck) {
    displayCharPositionWrite ( 10,1 );
    displayStringWrite( "SAFE" );
}
}


// turns on buzzer and red LED when alarm is activatec
void alarmAlert() {
    if (emergency == true) {
        red_LED = ON;
        alarmBuzzer = ON;
}
    else if (emergency == false) {
        red_LED = OFF;
        alarmBuzzer = OFF;
    }
}



//updates interface based on inputs
//updates display 
void user_InterfaceUpdate() {
displayChange();
Food_In();
Dark_Level();
alarmAlert();
}
