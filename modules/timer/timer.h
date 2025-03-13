//=====[#include guards - begin]===============================================

#ifndef _timer_h_
#define _timer_h_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================
extern int timeRemaining;
//=====[Declarations (prototypes) of public functions]=========================
void timerInit();
void startTimer();
void timerUpdate();
bool isTimerDone();
int getTimeRemaining();

//=====[#include guards - end]=================================================

#endif // _timer_h_
