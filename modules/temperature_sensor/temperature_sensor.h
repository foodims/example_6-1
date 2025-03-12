
//=====[#include guards - begin]===============================================

#ifndef _temperature_sensor_h_
#define _temperature_sensor_h_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void temperatureSensorInit();
void temperatureSensorUpdate();
float temperatureSensorReadCelsius();
float temperatureSensorReadFahrenheit();
float celsiusToFahrenheit( float tempInCelsiusDegrees );

//=====[#include guards - end]=================================================

#endif // _temperature_sensor_h_
