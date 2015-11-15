/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* INITIALIZATIONS */
    /* init tps and apps analog->digital converters */
    TPS_ADC_Start();
    APPS_ADC_Start();
    /* begin tps and apps analog->digital conversions */
    TPS_ADC_StartConvert();
    APPS_ADC_StartConvert();
    /* wait to fully convert all channels */
    TPS_ADC_IsEndConversion(TPS_ADC_WAIT_FOR_RESULT);
    APPS_ADC_IsEndConversion(APPS_ADC_WAIT_FOR_RESULT);

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
