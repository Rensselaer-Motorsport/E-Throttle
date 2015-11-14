#include <device.h>
#include <LED_RGB.h>

void main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint16 CapSensePosition;
    LED_RGB_Start();
    CyGlobalIntEnable;
    CapSense_1_Start();
    CapSense_1_InitializeAllBaselines();
    UART_1_Start();
     
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        CapSense_1_UpdateEnabledBaselines();
        CapSense_1_ScanEnabledWidgets();
        while(CapSense_1_IsBusy() != 0);
        CapSensePosition = CapSense_1_GetCentroidPos(CapSense_1_LINEARSLIDER0__LS);
        LED_RGB_SetColorCircle(255 * CapSensePosition);
        UART_1_UartPutChar(CapSensePosition);
        CyDelay(10);
    }
}

/* [] END OF FILE */
