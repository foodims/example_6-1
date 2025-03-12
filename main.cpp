
//=====[Libraries]=============================================================

#include "toaster_alert_system.h"
#include "user_interface.h"
//=====[Main function, the program entry point after power on or reset]========

int main()
{
    toasterAlertSystemInit();
    while (true) {
        displaychange();
        toasterAlertSystemUpdate();
    }
}
