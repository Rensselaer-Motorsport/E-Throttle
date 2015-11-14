#include <device.h>

void main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        Pin_Red_Write(~Pin_Red_Read());
        CyDelay(500);
    }
}

/* [] END OF FILE */
