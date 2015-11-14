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
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint16 ADCResult;
    uint16 PWMCompare = 0;
    
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    
    ADC_SAR_Seq_1_Start();
    PWM_1_Start();
    ADC_SAR_Seq_1_StartConvert();
    ADC_SAR_Seq_1_IsEndConversion(ADC_SAR_Seq_1_WAIT_FOR_RESULT);
    
    for(;;)
    {
        /* Place your application code here. */
        /**/
        ADCResult = ADC_SAR_Seq_1_GetResult16(0);
        PWM_1_WriteCompare(ADCResult);
        CyDelay(10);
        /**//*
        PWMCompare = PWMCompare + 1;
        if( PWMCompare >= 1000 )
            PWMCompare = 0;
        PWM_1_WriteCompare(PWMCompare);
        CyDelay(1);
        */
    }
}

/* [] END OF FILE */
