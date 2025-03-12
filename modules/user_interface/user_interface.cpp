//=====[Libraries]=============================================================
#include "mbed.h"
#include "arm_book_lib.h"
#include "user_interface.h"
#include <string>
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

DigitalOut green_LED(D12);
DigitalOut red_LED(D14);
DigitalOut alarmBuzzer(PE_10);

UnbufferedSerial uartUsb( USBTX, USBRX, 115200 );

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

bool buttonPressed = false;
bool toasterOn = false;
bool displayCheck = false;
const float light = 0.33;
const float dark = 0.66;

/*
// Helper function to calculate string length
size_t getStringLength(const char* str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void printMessage(const char* message) {
    uartUsb.write( message, getStringLength(message) );
}
*/
//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

// button configurations and initializations 

void InputsInit() {
in_Switch.mode(PullDown);
on_Switch.mode(PullDown);
}

void outputsInit() {
    green_LED = OFF;
    red_LED = OFF;
    alarmBuzzer = ON;
}

// determines if food is in toaster
void Food_In() {
if (in_Switch && !on_Switch) {
    buttonPressed = false;
    toasterOn = false;
    green_LED = OFF;
    red_LED = ON;
    alarmBuzzer = OFF;
    if (!buttonPressed) {
        uartUsb.write("Food is in toaster, please press start to begin toasting\r\n", 60);
        uartUsb.write("\r\n", 2);
        }
    }

if (in_Switch && on_Switch) {
    buttonPressed = true;
    toasterOn = true;
    green_LED = ON;
    red_LED = OFF;
    alarmBuzzer = ON;
    if (buttonPressed) {
        uartUsb.write("Food has been inserted in toaster and toaster is ON\r\n", 51);
        uartUsb.write("\r\n", 2);
        }
}
}


// determines desired darkness level of toast 
// corresponds with timer
const char* Dark_Level() {   
if (!toasterOn) {
    uartUsb.write("N/A\r\n", 5);  // Send "N/A" if toaster is off
    return "N/A";  // Return "N/A" if toaster is off
}

float levelselect = Potentiometer.read();
    if (levelselect < light) {
        //uartUsb.write("light\r\n", 7);
        return "light"; 
    }
    else if (levelselect > dark) {
        //uartUsb.write("dark\r\n", 6);
        return "dark";   
    }
    else {
        //uartUsb.write("medium\r\n", 8);
        return "medium"; 
    }
}

void displaychange() {
    displayInit();
    displayCharPositionWrite (0,0);
    displayStringWrite("Level:");



    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Time:" );
    /*
    char timeStr[4];
    sprintf(timeStr, "%d", getTimeRemaining());
    displayCharPositionWrite( 6,1 );
    displayStringWrite(timeStr);
*/
if (toasterOn) {
    displayCharPositionWrite( 7,0 );
    if (Dark_Level() == "light") {
        displayStringWrite("Light");
}
    else if (Dark_Level() == "medium") {
        displayStringWrite("Medium");
}
    else if (Dark_Level() == "dark") {
        displayStringWrite("Dark");
}
displayCheck = true;
}

    if (&alarmState && displayCheck){
        displayCharPositionWrite ( 10,1 );
        displayStringWrite( "DANGER" );
}
    else if (!&alarmState && displayCheck) {
        displayCharPositionWrite ( 10,1 );
        displayStringWrite( "SAFE" );
}
}


/*
void alarmalert() {
    if (alarmOn == true) {
        red_LED = ON;
        alarmBuzzer = OFF;
}
    else if (alarmOn == false) {
        red_LED = OFF;
        alarmBuzzer = ON;
    }
}
*/

//updates interface based on inputs
//updates display 
void user_InterfaceUpdate() {
displaychange();
Food_In();
Dark_Level();
//alarmalert();
}