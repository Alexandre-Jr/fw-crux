#ifndef ADCANALYSIS_H
#define ADCANALYSIS_H




/* Includes */

// ADC Analysis parts
#include "ADCAnalysis_tasks.h"
#include "ADCAnalysis_type.h"

// Standard C libraries
#include <stdbool.h>

// Linkarch framework
#include "linkarch.h"




/* ADC Analysis functions */

// Configure functions

bool ADCAnalysis_config(void);


// Get functions

float ADCAnalysis_getBatteryVoltage(uint8_t channel);
float ADCAnalysis_getCapacitorVoltage(uint8_t channel);




#endif // ADCANALYSIS_H