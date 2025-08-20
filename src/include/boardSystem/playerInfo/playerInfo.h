#ifndef PLAYERINFO_H
#define PLAYERINFO_H




/* Includes */

// Standard C libraries
#include <stdbool.h>

// Linkarch framework
#include "linkarch.h"




/* Player Info functions */

// Configure functions

bool playerInfo_config(void);


// Get functions

uint8_t playerInfo_getPlayerId(void);




#endif // PLAYERINFO_H