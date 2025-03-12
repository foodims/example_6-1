
//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "temperature_sensor.h"

//=====[Declaration of private defines]========================================

// number of samples taken to determine average reading
#define Temp_Sensor_SAMPLES    10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn T_Sensor(A0);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

float TempC = 0.0;
float TempSensorReadings[Temp_Sensor_SAMPLES];

//=====[Declarations (prototypes) of private functions]========================

static float analogReadingScaledWithTheLM35Formula( float analogReading );

//=====[Implementations of public functions]===================================

//initializes sensor
void temperatureSensorInit()
{
    int i;
    
    for( i=0; i<Temp_Sensor_SAMPLES ; i++ ) {
        TempSensorReadings[i] = 0;
    }
}

//updates sensor
void temperatureSensorUpdate()
{
    static int TempSensorSampleIndex = 0;
    float TempSensorReadingsSum = 0.0;
    float TempSensorReadingsAverage = 0.0;

    int i = 0;

    TempSensorReadings[TempSensorSampleIndex] = T_Sensor.read();
       TempSensorSampleIndex++;
    if ( TempSensorSampleIndex >= Temp_Sensor_SAMPLES) {
        TempSensorSampleIndex = 0;
    }
    
   TempSensorReadingsSum = 0.0;
    for (i = 0; i < Temp_Sensor_SAMPLES; i++) {
        TempSensorReadingsSum = TempSensorReadingsSum + TempSensorReadings[i];
    }
    TempSensorReadingsAverage = TempSensorReadingsSum / Temp_Sensor_SAMPLES;
       TempC = analogReadingScaledWithTheLM35Formula ( TempSensorReadingsAverage );    
}

//returns temperature average in celcius
float temperatureSensorReadCelsius()
{
    return TempC;
}

// convert celcius to fahrenheit
float celsiusToFahrenheit( float tempInCelsiusDegrees )
{
    return ( tempInCelsiusDegrees * 9.0 / 5.0 + 32.0 );
}

//returns temperature average in fahrenheit
float temperatureSensorReadFahrenheit()
{
    return celsiusToFahrenheit( TempC );
}

//=====[Implementations of private functions]==================================

//voltage scaling to 3.3V 
static float analogReadingScaledWithTheLM35Formula( float analogReading )
{
    return ( analogReading * 3.3 / 0.01 );
}
