#include "ADCAnalysis.h"
#include "ADCAnalysis_private.h"




/* Global variables */

ADCAnalysis_t ADCAnalysis;




/* ADC Analysis functions */

// Configure functions

bool ADCAnalysis_config(void)
{

    // TODO: This function should configure the ADC Analysis system.
    LINKARCH_DEBUG_MESSAGE("Configuring ADC Analysis system...");
    //linkarch_hal_gpio_adc_init();
    //linkarch_hal_gpio_adc_initPin(28);
    return true;

}

/* ADC Analysis tasks functions */

void ADCAnalysis_runningTask(void)
{

    // TODO: This function should run the ADC Analysis tasks.
    LINKARCH_DEBUG_MESSAGE("Running ADC Analysis tasks...");
    //float adcValue = linkarch_hal_gpio_adc_read(28); 
    //LINKARCH_DEBUG_MESSAGE("ADC Value: %f", adcValue);

}