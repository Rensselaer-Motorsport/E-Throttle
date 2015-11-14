#include <device.h>
#include <LED_RGB.h>

void main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint16 ADCResult;
    LED_RGB_Start();
    
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
    ADC_SAR_Seq_1_IsEndConversion(ADC_SAR_Seq_1_WAIT_FOR_RESULT);
    
    for(;;)
    {
        /* Place your application code here. */
        ADCResult = ADC_SAR_Seq_1_GetResult16(0);
        LED_RGB_SetColorRGB(ADCResult * (65535 / 2048), 0, 0);
        CyDelay(10);
    }
}

/* [] END OF FILE */
