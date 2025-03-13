
//=====[Libraries]=============================================================

#include "toaster_alert_system.h"
#include "user_interface.h"

//=====[Main function, the program entry point after power on or reset]========

//runs initialization functions
// updates display
// loops over update functions
int main()
{
    toasterAlertSystemInit();
    while (true) {
        displayChange();
        toasterAlertSystemUpdate();
    }
}
