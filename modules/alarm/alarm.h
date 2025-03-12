//=====[#include guards - begin]===============================================

#ifndef _alarm_h_
#define _alarm_h_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================
extern bool alarmOn;
//=====[Declarations (prototypes) of public functions]=========================

void alarmSystemInit();
void alarmUpdate();
void alarmState(bool state);

//=====[#include guards - end]=================================================

#endif // _alarm_h_