#include "boardSystem.h"
#include "boardSystem_private.h"




/* Global Variables */

// Module configuration

linkarch_module_t listOfModules[] = 
{

    LINKARCH_MODULE_INIT(BOARD_SYSTEM_MODULE_ADCANALYSIS, "ADCAnalysis", ADCAnalysis_config, LINKARCH_MODULETYPE_LOOP_CLOCKED, ADCANALYSIS_PERIODMS, ADCANALYSIS_STACKSIZE, ADCANALYSIS_PRIORITY, ADCANALYSIS_COREAFFINITY, ADCANALYSIS_CORENUMBER),
    LINKARCH_MODULE_INIT(BOARD_SYSTEM_MODULE_COMMAND, "command", command_config, LINKARCH_MODULETYPE_LOOP_CLOCKED, COMMAND_PERIODMS, COMMAND_STACKSIZE, COMMAND_PRIORITY, COMMAND_COREAFFINITY, COMMAND_CORENUMBER),
    LINKARCH_MODULE_INIT(BOARD_SYSTEM_MODULE_KICKCONTROL, "kickControl", kickControl_config, LINKARCH_MODULETYPE_LOOP_CLOCKED, KICKCONTROL_PERIODMS, KICKCONTROL_STACKSIZE, KICKCONTROL_PRIORITY, KICKCONTROL_COREAFFINITY, KICKCONTROL_CORENUMBER),
    LINKARCH_MODULE_INIT(BOARD_SYSTEM_MODULE_MOTORCONTROL, "motorControl", motorControl_config, LINKARCH_MODULETYPE_LOOP_CLOCKED, MOTORCONTROL_PERIODMS, MOTORCONTROL_STACKSIZE, MOTORCONTROL_PRIORITY, MOTORCONTROL_COREAFFINITY, MOTORCONTROL_CORENUMBER),
    LINKARCH_MODULE_INIT(BOARD_SYSTEM_MODULE_ONBOARDDEBUG, "onBoardDebug", onBoardDebug_config, LINKARCH_MODULETYPE_LOOP_CLOCKED, ONBOARDDEBUG_PERIODMS, ONBOARDDEBUG_STACKSIZE, ONBOARDDEBUG_PRIORITY, ONBOARDDEBUG_COREAFFINITY, ONBOARDDEBUG_CORENUMBER),
    
};


// Modes configuration

linkarch_modeConfigToModule_t runningMode_modulesConfig[] = 
{

    LINKARCH_MODECONFIGTTOMODULE_INIT(NULL, ADCAnalysis_runningTask, NULL),
    LINKARCH_MODECONFIGTTOMODULE_INIT(NULL, command_runningTask, NULL),
    LINKARCH_MODECONFIGTTOMODULE_INIT(NULL, kickControl_runningTask, NULL),
    LINKARCH_MODECONFIGTTOMODULE_INIT(NULL, motorControl_runningTask, NULL),
    LINKARCH_MODECONFIGTTOMODULE_INIT(NULL, onBoardDebug_runningTask, NULL),

};

linkarch_mode_t listOfModes[] = 
{

    LINKARCH_MODE_INIT(RUNNING_MODE, "runningMode", runningMode_modulesConfig),

};


// Mode transitions

linkarch_controller_modeTransition_t listOfModeTransitions[] = 
{

    LINKARCH_MODETRANSITION_INIT(STAYRUNNING_MODETRANSITION, "stayRunning", RUNNING_MODE, RUNNING_MODE, NULL, NULL),

};


// Controller

linkarch_controller_t controller = LINKARCH_CONTROLLER_INIT(listOfModules, listOfModes, listOfModeTransitions);




/* Board System functions */

// Initialize the board system

int boardSystem_init(void)
{

    if(!linkarch_hal_mcuInit()) return -1;
    if(!linkarch_controller_config(&controller, RUNNING_MODE)) return -1;
    if(!linkarch_controller_startSystem()) return -1;

    while(1){}
    return 0;

}


// Configure the osal (OS Abstraction Layer) application hooks (obligatory functions)

void linkarch_osal_aplicationStackOverflowHook()
{

    LINKARCH_MESSAGE("Stack overflow detected");

}

void linkarch_osal_aplicationMallocFailedHook()
{

    LINKARCH_MESSAGE("Malloc failed");

}

void linkarch_osal_aplicationTickHook()
{

    

}