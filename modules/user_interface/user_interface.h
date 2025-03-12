
//=====[#include guards - begin]===============================================
#ifndef _user_interface_h_
#define _user_interface_h_
//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================
extern bool displayCheck;
extern bool buttonPressed;
extern bool toasterReady;
extern bool toasterOn;
//=====[Declarations (prototypes) of public functions]=========================
void InputsInit();
void outputsInit();
void Food_In();
const char * Dark_Level();
void displaychange();
//void alarmalert();
void user_InterfaceUpdate();
//=====[#include guards - end]=================================================
#endif // _user_interface_h_
