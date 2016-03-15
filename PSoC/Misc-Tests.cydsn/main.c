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
    ADC_Start();
    PWM_Start();

        
    union {
        char str[4];
        int num;
    } pot_0;    
    

    int compare;
    uint16 adc = 255;
    int mycount = 0;
    
    for(;;)
    { 
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        ADC_StopConvert();

        adc = ADC_GetResult16();
        
        if(adc > 255)
        {
            if(adc == 0xFFFF) 
            {
                adc = 0x00;
            }
            else
            adc = 0xFF; 
        } 
        
        compare = (uint16)(1000 + ((float)((float)((float)adc / (float)255) * (float)1000)));
        
        
        //compare = mycount;
        PWM_WriteCompare(compare);
//        PWM_WritePeriod(compare + 39999);
        
//        mycount++;
//        mycount = mycount % 2000;
        
        pot_0.num = compare;
        outputNum(pot_0.str);
        CyDelay(20);
    }
}

void outputPad() {
    int i; 
    for (i = 0; i < 4; i++) {
        UART_1_PutChar(0xFF);
    }
}


void outputNum(char* num) {  
    outputPad();
    UART_1_PutChar(num[0]);
    UART_1_PutChar(num[1]);
    UART_1_PutChar(num[2]);
    UART_1_PutChar(num[3]);
    outputPad();
}


/* [] END OF FILE */
