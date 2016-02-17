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

void outputNum(char*);

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_1_Start();
    ADC_DelSig_Start();
    
    union {
        char str[4];
        int num;
    } pot_0;
    
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    { 
        // Run an ADC convert and store the values in the pot_0/pot_1.num
        //ADC_DelSig_StartConvert();
        //ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT);
        //pot_0.num = ADC_DelSig_GetResult16();
        
        pot_0.num = ADC_DelSig_Read16();
        
        outputNum(pot_0.str);
                
        CyDelay(100);
    }
}

void outputNum(char* num) {
    UART_1_PutChar(num[0]);
    UART_1_PutChar(num[1]);
    UART_1_PutChar(num[2]);
    UART_1_PutChar(num[3]);
}

/* [] END OF FILE */
