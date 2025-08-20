#ifndef COMMAND_PRIVATE_H
#define COMMAND_PRIVATE_H




/* Includes */

// Command parts
#include "command_protocol.h"




/* Command private functions */

// Configure functions
static bool command_radioConfig(void);
static bool command_radioReconfig(void);

// Handle functions
static bool command_handleRadioCommand(radioCommand_t * radioCommand);

// Read functions
static bool command_readRadioCommand(radioCommand_t * radioCommand);

// Validate functions
static bool command_isReadyToReadRadioBuffer(void);
static bool command_isRadioCommandValid(radioCommand_t * radioCommand);
static bool command_isNotReceivedPacketsCountOverflown(void);




#endif // COMMAND_PRIVATE_H