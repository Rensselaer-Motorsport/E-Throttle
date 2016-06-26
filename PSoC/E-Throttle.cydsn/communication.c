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

#include "communication.h"

/*
parameters: sens - The sensor, defined in "global_constants.h"
            percent - The percentage the potentiometer is open
effect:     Sends percent over UART labeled as coming from sensor
            sens
*/
void send_pot_data(sensor sens, float percent) {
    output_pad();
    switch (sens) {
        case TPS0:
            UART_PutString("TPS0");
            break;
        case TPS1:
            UART_PutString("TPS1");
            break;
        case APPS0:
            UART_PutString("APS0");
            break;
        case APPS1:
            UART_PutString("APS1");
            break;
        case BRAKE:
            UART_PutString("BRAK");
            break;
        default:
            UART_PutString("ERRR");
    }
    // output pad at beginning and end of output_int
    output_int((int)percent * 100);
}

/*
parameters: target_num - The number to be sent over UART
effect:     Sends num over UART as 4 separate bytes
*/
void output_int(int target_num) {
    // Create union to access each byte of number separately
    union {
        char str[4];
        int num;
    } byte_overlap;
    
    byte_overlap.num = target_num;
    
    UART_PutChar(byte_overlap.str[0]);
    UART_PutChar(byte_overlap.str[1]);
    UART_PutChar(byte_overlap.str[2]);
    UART_PutChar(byte_overlap.str[3]);
}

/*
effect:     Sends 4 bytes of all 1s over uart (0xFFFFFFFF)
*/
void output_pad() {
    int i; 
    for (i = 0; i < 4; i++) {
        UART_PutChar(0xFF);
    }
}

/* [] END OF FILE */
