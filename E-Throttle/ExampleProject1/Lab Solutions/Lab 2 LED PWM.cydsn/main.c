#include <device.h>

void main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint16 PWMCompare;
    PWM_1_Start();

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        PWMCompare = PWMCompare + 1;
        if( PWMCompare >= 1000 )
            PWMCompare = 0;
        PWM_1_WriteCompare(PWMCompare);
        CyDelay(1);
    }
}

/* [] END OF FILE */
