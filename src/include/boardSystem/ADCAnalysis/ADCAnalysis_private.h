#ifndef ADCANALYSIS_PRIVATE_H
#define ADCANALYSIS_PRIVATE_H




/* Includes */

// ADC Analysis parts
#include "ADCAnalysis_type.h"
#include "ADCAnalysis_config.h"

// Standard C libraries
#include <stdint.h>




/* ADC Analysis private functions */

// Configure functions
static bool ADCAnalysis_configureADC(void);
static bool ADCAnalysis_configureADCChannels(void);

// Read functions
static float ADCAnalysis_readBatteryVoltage();
static float ADCAnalysis_readCapacitorVoltage();

// Convert functions
static float ADCAnalysis_convertVoltageSampleToBatteryVoltage(float sample);
static float ADCAnalysis_convertVoltageSampleToCapacitorVoltage(float sample);

// Calculate functions
static float ADCAnalysis_calculateAverage(float *samples, uint8_t numberOfSamples);




#endif // ADCANALYSIS_PRIVATE_H