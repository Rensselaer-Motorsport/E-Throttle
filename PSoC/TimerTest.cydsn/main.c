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
#include "communication.h"

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        Timer_1_WriteCounter(Timer_1_ReadPeriod());
        Timer_1_Start();
        //Timer_1_Init();
        int count = Timer_1_ReadCounter();
        int start = count;
        //output_pad();
        //output_int(count);
        
        CyDelay(1000);
        
        count = Timer_1_ReadCounter();
        int stop = count;
        //output_pad();
        //output_int(count);
        output_pad();
        output_int((start - stop) / 32);
        //output_pad();
        //output_int(999999999);
        Timer_1_Stop();
    }
}

/* [] END OF FILE */
