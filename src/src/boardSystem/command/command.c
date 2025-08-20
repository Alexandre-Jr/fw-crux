#include "command.h"
#include "command_private.h"




/* Global variables */

command_t Command;




/* Command functions */

// Configure functions

bool command_config()
{

    // TODO: This function should configure the command system.
    LINKARCH_DEBUG_MESSAGE("Configuring command system...");

    NRF24L01P_init(&Command.radio, 0, 17, 16, 15, 14, 99, 0, linkarch_osal_delayMs);
    NRF24L01P_config(&Command.radio);

    return true;

}


/* Command tasks functions */

void command_runningTask()
{

    // TODO: This function should run the command tasks.
    LINKARCH_DEBUG_MESSAGE("Running command tasks...");

}