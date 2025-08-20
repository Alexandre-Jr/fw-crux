#ifndef COMMAND_TYPE_H
#define COMMAND_TYPE_H




/* Includes */

// Standard C libraries
#include <stdint.h>

// NRF24l01p
#include "nrf24l01p.h"




/* Command Type */

typedef struct
{

    NRF24L01P radio;
    uint32_t noReceivedPacketsCount;

} command_t;




/* Macros */

#define COMMAND_INIT() \
    { \
        .radio, \
        .noReceivedPacketsCount = 0 \
    }

    


#endif // COMMAND_TYPE_H