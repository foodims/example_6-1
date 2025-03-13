//=====[#include guards - begin]===============================================

#ifndef _alarm_h_
#define _alarm_h_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================
extern bool emergency;
extern bool alarmOn;
//=====[Declarations (prototypes) of public functions]=========================

void alarmSystemInit();
void alarmUpdate();


//=====[#include guards - end]=================================================

#endif // _alarm_h_