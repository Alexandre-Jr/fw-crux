#include "motorControl.h"
#include "motorControl_private.h"




/* Motor Control functions */

// Configure functions

bool motorControl_config(void)
{

    // TODO: This function should configure the motor control system.
    LINKARCH_DEBUG_MESSAGE("Configuring motor control system...");
    //linkarch_hal_pwm_initPWM(25, 125.1, 50.1, 50.1);
    return true;

}


/* Motor Control tasks functions */

void motorControl_runningTask(void)
{

    // TODO: This function should run the motor control tasks.
    LINKARCH_DEBUG_MESSAGE("Running motor control tasks...");
    //linkarch_hal_pwm_setDutyCycle(25, 125.2, 50, 50.1); // Set duty cycle to 50%


}