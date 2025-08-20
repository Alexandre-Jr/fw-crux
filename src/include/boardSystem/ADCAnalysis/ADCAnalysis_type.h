#ifndef ADCANALYSIS_TYPE_H
#define ADCANALYSIS_TYPE_H




/* Includes */

// ADC Analysis parts
#include "ADCAnalysis_config.h"




/* ADC Analysis Type */

typedef struct
{

    float batteryVoltageSamples[ADCANALYSIS_NUMBER_OF_SAMPLES_FOR_BATTERY_VOLTAGE_VALUE];
    float capacitorVoltageSamples[ADCANALYSIS_NUMBER_OF_SAMPLES_FOR_CAPACITOR_VOLTAGE_VALUE];

} ADCAnalysis_t;




#endif // ADCANALYSIS_TYPE_H