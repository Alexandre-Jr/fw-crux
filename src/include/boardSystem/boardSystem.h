#ifndef BOARDSYSTEM_H
#define BOARDSYSTEM_H




/* Includes */

// Modules
#include "ADCAnalysis.h"
#include "command.h"
#include "kickControl.h"
#include "motorControl.h"
#include "onBoardDebug.h"

// Board System Parts
#include "boardSystem_config.h"

// Linkarch framework
#include "linkarch.h"




/* Board System functions */

// Initialize the board system

int boardSystem_init(void);




#endif // BOARDSYSTEM_H