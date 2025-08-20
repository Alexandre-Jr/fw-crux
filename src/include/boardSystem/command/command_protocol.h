#ifndef COMMAND_PROTOCOL_H
#define COMMAND_PROTOCOL_H




/* Includes */

// Standard C libraries
#include <stdint.h>




/* Command Protocol */

typedef struct WRMagicCommand radioCommand_t;

// This structure is standardized protocol in Warthog Robotics for all Hercules robots
typedef struct WRMagicCommand {
    uint8_t  kickType;
    uint8_t  kickPower;
    uint32_t nonce;
    float  playerSpeeds[4];
    float  dribblerSpeed;
} WRMagicCommand;




/* Command Protocol Functions */

bool command_bufferToRadioCommand(radioCommand_t * radioCommand, uint8_t *buffer);




#endif // COMMAND_PROTOCOL_H