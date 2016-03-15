/*******************************************************************************
* File Name: I2CM_I2C_MASTER.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  I2C Master mode.
*
* Note:
*
*******************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2CM_PVT.h"
#include "I2CM_I2C_PVT.h"

#if(I2CM_I2C_MASTER_CONST)

/***************************************
*      I2C Master Private Vars
***************************************/

/* Master variables */
volatile uint16 I2CM_mstrStatus;      /* Master Status byte  */
volatile uint8  I2CM_mstrControl;     /* Master Control byte */

/* Receive buffer variables */
volatile uint8 * I2CM_mstrRdBufPtr;   /* Pointer to Master Read buffer */
volatile uint32  I2CM_mstrRdBufSize;  /* Master Read buffer size       */
volatile uint32  I2CM_mstrRdBufIndex; /* Master Read buffer Index      */

/* Transmit buffer variables */
volatile uint8 * I2CM_mstrWrBufPtr;   /* Pointer to Master Write buffer */
volatile uint32  I2CM_mstrWrBufSize;  /* Master Write buffer size       */
volatile uint32  I2CM_mstrWrBufIndex; /* Master Write buffer Index      */
volatile uint32  I2CM_mstrWrBufIndexTmp; /* Master Write buffer Index Tmp */


/*******************************************************************************
* Function Name: I2CM_I2CMasterWriteBuf
********************************************************************************
*
* Summary:
*  Automatically writes an entire buffer of data to a slave device. Once the
*  data transfer is initiated by this function, further data transfer is handled
*  by the included ISR in byte by byte mode.
*
* Parameters:
*  slaveAddr: 7-bit slave address.
*  xferData:  Pointer to buffer of data to be sent.
*  cnt:       Size of buffer to send.
*  mode:      Transfer mode defines: start or restart condition generation at
*             begin of the transfer and complete the transfer or halt before
*             generating a stop.
*
* Return:
*  Status error - zero means no errors.
*
* Global variables:
*  I2CM_mstrStatus  - used to store current status of I2C Master.
*  I2CM_state       - used to store current state of software FSM.
*  I2CM_mstrControl - used to control master end of transaction with
*  or without the Stop generation.
*  I2CM_mstrWrBufPtr - used to store pointer to master write buffer.
*  I2CM_mstrWrBufIndex - used to current index within master write
*  buffer.
*  I2CM_mstrWrBufSize - used to store master write buffer size.
*
*******************************************************************************/
uint32 I2CM_I2CMasterWriteBuf(uint32 slaveAddress, uint8 * wrData, uint32 cnt, uint32 mode)
{
    uint32 errStatus;

    errStatus = I2CM_I2C_MSTR_NOT_READY;

    if(NULL != wrData)  /* Check buffer pointer */
    {
        /* Check FSM state and bus before generate Start/ReStart condition */
        if(I2CM_CHECK_I2C_FSM_IDLE)
        {
            I2CM_SCB_IRQ_Disable();

            /* Check the bus state */
            errStatus = I2CM_CHECK_I2C_STATUS(I2CM_I2C_STATUS_BUS_BUSY) ?
                            I2CM_I2C_MSTR_BUS_BUSY : I2CM_I2C_MSTR_NO_ERROR;
        }
        else if(I2CM_CHECK_I2C_FSM_HALT)
        {
            I2CM_mstrStatus &= (uint16) ~I2CM_I2C_MSTAT_XFER_HALT;
                              errStatus  = I2CM_I2C_MSTR_NO_ERROR;
        }
        else
        {
            /* Unexpected FSM state: exit */
        }
    }


    /* Check if the Master is ready to start  */
    if(I2CM_I2C_MSTR_NO_ERROR == errStatus) /* No error proceed */
    {
        /* Setup write transcation */
        I2CM_state = I2CM_I2C_FSM_MSTR_WR_ADDR;
        I2CM_mstrWrBufIndexTmp = 0u;
        I2CM_mstrWrBufIndex    = 0u;
        I2CM_mstrWrBufSize     = cnt;
        I2CM_mstrWrBufPtr      = (volatile uint8 *) wrData;
        I2CM_mstrControl       = (uint8) mode;

        slaveAddress = I2CM_GET_I2C_8BIT_ADDRESS(slaveAddress);

        I2CM_mstrStatus &= (uint16) ~I2CM_I2C_MSTAT_WR_CMPLT;

        I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_ALL);
        I2CM_ClearTxInterruptSource(I2CM_INTR_TX_UNDERFLOW);
        /* The TX and RX FIFO have to be EMPTY */

        /* Generate Start or ReStart */
        if(I2CM_CHECK_I2C_MODE_RESTART(mode))
        {
            I2CM_I2C_MASTER_GENERATE_RESTART;
            I2CM_TX_FIFO_WR_REG = slaveAddress;
        }
        else
        {
            I2CM_TX_FIFO_WR_REG = slaveAddress;
            I2CM_I2C_MASTER_GENERATE_START;
        }

         /* Catch when address will be sent */
        I2CM_SetTxInterruptMode(I2CM_INTR_TX_UNDERFLOW);
    }

    I2CM_SCB_IRQ_Enable();

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterReadBuf
********************************************************************************
*
* Summary:
*  Automatically writes an entire buffer of data to a slave device. Once the
*  data transfer is initiated by this function, further data transfer is handled
*  by the included ISR in byte by byte mode.
*
* Parameters:
*  slaveAddr: 7-bit slave address.
*  xferData:  Pointer to buffer where to put data from slave.
*  cnt:       Size of buffer to read.
*  mode:      Transfer mode defines: start or restart condition generation at
*             begin of the transfer and complete the transfer or halt before
*             generating a stop.
*
* Return:
*  Status error - zero means no errors.
*
* Global variables:
*  I2CM_mstrStatus  - used to store current status of I2C Master.
*  I2CM_state       - used to store current state of software FSM.
*  I2CM_mstrControl - used to control master end of transaction with
*  or without the Stop generation.
*  I2CM_mstrRdBufPtr - used to store pointer to master write buffer.
*  I2CM_mstrRdBufIndex - used to current index within master write
*  buffer.
*  I2CM_mstrRdBufSize - used to store master write buffer size.
*
*******************************************************************************/
uint32 I2CM_I2CMasterReadBuf(uint32 slaveAddress, uint8 * rdData, uint32 cnt, uint32 mode)
{
    uint32 errStatus;

    errStatus = I2CM_I2C_MSTR_NOT_READY;

    if(NULL != rdData)
    {
        /* Check FSM state and bus before generate Start/ReStart condition */
        if(I2CM_CHECK_I2C_FSM_IDLE)
        {
            I2CM_SCB_IRQ_Disable();

            /* Check the bus state */
            errStatus = I2CM_CHECK_I2C_STATUS(I2CM_I2C_STATUS_BUS_BUSY) ?
                            I2CM_I2C_MSTR_BUS_BUSY : I2CM_I2C_MSTR_NO_ERROR;
        }
        else if(I2CM_CHECK_I2C_FSM_HALT)
        {
            I2CM_mstrStatus &= (uint16) ~I2CM_I2C_MSTAT_XFER_HALT;
                              errStatus  =  I2CM_I2C_MSTR_NO_ERROR;
        }
        else
        {
            /* Unexpected FSM state: exit */
        }
    }

    /* Check the Master ready to proceed */
    if(I2CM_I2C_MSTR_NO_ERROR == errStatus) /* No error proceed */
    {
        /* Setup read transfer */
        I2CM_state = I2CM_I2C_FSM_MSTR_RD_ADDR;
        I2CM_mstrRdBufIndex = 0u;
        I2CM_mstrRdBufSize  = cnt;
        I2CM_mstrRdBufPtr   = (volatile uint8 *) rdData;
        I2CM_mstrControl    = (uint8) mode;

        slaveAddress = (I2CM_GET_I2C_8BIT_ADDRESS(slaveAddress) | I2CM_I2C_READ_FLAG);

        I2CM_mstrStatus &= (uint16) ~I2CM_I2C_MSTAT_RD_CMPLT;

        I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_ALL);

        /* The TX and RX FIFO have to be EMPTY */

        /* Generate Start or ReStart */
        if(I2CM_CHECK_I2C_MODE_RESTART(mode))
        {
            I2CM_I2C_MASTER_GENERATE_RESTART;
            I2CM_TX_FIFO_WR_REG = (slaveAddress);
        }
        else
        {
            I2CM_TX_FIFO_WR_REG = (slaveAddress);
            I2CM_I2C_MASTER_GENERATE_START;
        }

        /* Prepare reaing */
        if(I2CM_mstrRdBufSize < I2CM_I2C_FIFO_SIZE) /* Reading byte-by-byte */
        {
            I2CM_SetRxInterruptMode(I2CM_INTR_RX_NOT_EMPTY);
        }
        else /* Reading use RX FIFO */
        {
            I2CM_ENABLE_MASTER_AUTO_DATA_ACK;
            I2CM_SetRxInterruptMode(I2CM_INTR_RX_FULL);
        }
    }

    I2CM_SCB_IRQ_Enable();

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterSendStart
********************************************************************************
*
* Summary:
*  Generates Start condition and sends slave address with read/write bit.
*
* Parameters:
*  slaveAddress:  7-bit slave address.
*  bitRnW:        Zero, send write command, non-zero send read command.
*
* Return:
*  Status error - zero means no errors.
*
* Side Effects:
*  This function is entered without a 'byte complete' bit set in the I2C_CSR
*  register. It does not exit until it will be set.
*
* Global variables:
*  I2CM_state - used to store current state of software FSM.
*
*******************************************************************************/
uint32 I2CM_I2CMasterSendStart(uint32 slaveAddress, uint32 bitRnW)
{
    uint32 errStatus;
    uint8  enableInterrupts;
    
    errStatus        = I2CM_I2C_MSTR_NOT_READY;
    enableInterrupts = 0u;
    
    /* Check FSM state before generate Start condition */
    if(I2CM_CHECK_I2C_FSM_IDLE)
    {
        /* If bus is free, generate Start condition */
        if(I2CM_CHECK_I2C_STATUS(I2CM_I2C_STATUS_BUS_BUSY))
        {
            errStatus = I2CM_I2C_MSTR_BUS_BUSY;
        }
        else
        {
            I2CM_SCB_IRQ_Disable(); /* Disable interrupt: the manual APIs don't require it */

            slaveAddress = I2CM_GET_I2C_8BIT_ADDRESS(slaveAddress);

            if(0u == bitRnW) /* Write direction */
            {
                I2CM_state = I2CM_I2C_FSM_MSTR_WR_DATA;
            }
            else /* Read direction */
            {
                I2CM_state = I2CM_I2C_FSM_MSTR_RD_DATA;
                         slaveAddress |= I2CM_I2C_READ_FLAG;
            }

            /* The TX and RX FIFO have to be EMPTY */

            I2CM_TX_FIFO_WR_REG = slaveAddress; /* Put address in TX FIFO */
            I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_ALL);

            I2CM_I2C_MASTER_GENERATE_START;


            while(!I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ACK      |
                                                      I2CM_INTR_MASTER_I2C_NACK     |
                                                      I2CM_INTR_MASTER_I2C_ARB_LOST | 
                                                      I2CM_INTR_MASTER_I2C_BUS_ERROR))
            {
                /* 
                * Write: wait until address will be transfered 
                * Read : wait until address will be tranfered, the data byte is going to RX FIFO as well.
                */
            }

            /* 
            * Check results of address phase: 
            *  ACK  - address was ACKed continue.
            *  NACK - address was NACKed continue.
            *  LOST_ARB - SDA line is not match to what master drives: 
            *  lost arbitration or misplaced Start. Place: 7-bits address and RnW bit.
            *  The misplaced Start is possible when SCB drives SDA 1 and it changes to 0, when SCL is 1.
            *  BUS_ERR - misplaced Start or Stop when Slave drives. Place: ACK/NACK bit.
            *  The misplaced Start or Stop causes the bus idle status to get stuck to busy.
            *  The misplaced Start is possible when SCB drives SCL 1 and it changes 
            *  from 1 to 0 (Start) or 0 to 1 (Stop).
            *  Reset SCB on either LOST_ARB or BUS_ERR as both could be caused by
            *  misplaced Start event to reset bus busy.
            */
            if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ACK))
            {
                errStatus = I2CM_I2C_MSTR_NO_ERROR;
            }
            else if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_NACK))
            {
                errStatus = I2CM_I2C_MSTR_ERR_LB_NAK;
            }
            else if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ARB_LOST))
            {
                I2CM_state = I2CM_I2C_FSM_IDLE;
                             errStatus = I2CM_I2C_MSTR_ERR_ARB_LOST;
                      enableInterrupts = I2CM_I2C_RESET_ERROR;
            }
            else /* I2CM_INTR_MASTER_I2C_BUS_ERROR set is else condition */
            {
                I2CM_state = I2CM_I2C_FSM_IDLE;
                             errStatus = I2CM_I2C_MSTR_ERR_BUS_ERR;
                      enableInterrupts = I2CM_I2C_RESET_ERROR;
            }

            I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_I2C_ACK      |
                                                        I2CM_INTR_MASTER_I2C_NACK     |
                                                        I2CM_INTR_MASTER_I2C_ARB_LOST |
                                                        I2CM_INTR_MASTER_I2C_BUS_ERROR);
            
            /* Reset block in case of: LOST_ARB or BUS_ERR */
            if(0u != enableInterrupts)
            {
                enableInterrupts = CyEnterCriticalSection();
                I2CM_SCB_SW_RESET;
                CyExitCriticalSection(enableInterrupts);
            }
        }
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterSendRestart
********************************************************************************
*
* Summary:
*  Generates ReStart condition and sends slave address with read/write bit.
*
* Parameters:
*  slaveAddress:  7-bit slave address.
*  bitRnW:        Zero, send write command, non-zero send read command.
*
* Return:
*  Status error - zero means no errors.
*
* Side Effects:
*  This function is entered without a 'byte complete' bit set in the I2C_CSR
*  register. It does not exit until it will be set.
*
* Global variables:
*  I2CM_state - used to store current state of software FSM.
*
*******************************************************************************/
uint32 I2CM_I2CMasterSendRestart(uint32 slaveAddress, uint32 bitRnW)
{
    uint32 errStatus;
    uint8  enableInterrupts;

    errStatus        = I2CM_I2C_MSTR_NOT_READY;
    enableInterrupts = 0u;

    /* Check FSM state before generate ReStart condition */
    if(I2CM_CHECK_I2C_MASTER_ACTIVE)
    {
        slaveAddress = I2CM_GET_I2C_8BIT_ADDRESS(slaveAddress);

        if(0u == bitRnW) /* Write direction */
        {
            I2CM_state = I2CM_I2C_FSM_MSTR_WR_DATA;
        }
        else  /* Read direction */
        {
            I2CM_state  = I2CM_I2C_FSM_MSTR_RD_DATA;
                      slaveAddress |= I2CM_I2C_READ_FLAG;
        }

        /* The TX and RX FIFO have to be EMPTY */

        /* Clean-up interrupt status */
        I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_ALL);

        /* 
        * Generates a START - the restart should be set first and then address need to be put,
        * Because on write the byte in TX FIFO treated as DATA byte. ReStart will not be generated 
        */
        I2CM_I2C_MASTER_GENERATE_RESTART;

        while(I2CM_CHECK_I2C_MASTER_CMD(I2CM_I2C_MASTER_CMD_M_START))
        {
            /* Wait until ReStart will be generated */
        }

        /* Put address into TX FIFO */
        I2CM_TX_FIFO_WR_REG = slaveAddress;

        /* Wait for the address to be transfered */
        while(!I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ACK      |
                                                  I2CM_INTR_MASTER_I2C_NACK     |
                                                  I2CM_INTR_MASTER_I2C_ARB_LOST |
                                                  I2CM_INTR_MASTER_I2C_BUS_ERROR))
        {
            /* Wait until address will be transfered */
        }

        /* Check results of address phase: look into I2CM_I2CMasterSendStart for description */
        if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ACK))
        {
            errStatus = I2CM_I2C_MSTR_NO_ERROR;
        }
        else if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_NACK))
        {
             errStatus = I2CM_I2C_MSTR_ERR_LB_NAK;
        }
        else if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ARB_LOST))
        {
            I2CM_state = I2CM_I2C_FSM_IDLE;
                         errStatus = I2CM_I2C_MSTR_ERR_ARB_LOST;
                  enableInterrupts = I2CM_I2C_RESET_ERROR;
        }
        else /* I2CM_INTR_MASTER_I2C_BUS_ERROR set is else condition */
        {
            I2CM_state = I2CM_I2C_FSM_IDLE;
                         errStatus = I2CM_I2C_MSTR_ERR_BUS_ERR;
                  enableInterrupts = I2CM_I2C_RESET_ERROR;
        }

        I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_I2C_ACK      |
                                                    I2CM_INTR_MASTER_I2C_NACK     |
                                                    I2CM_INTR_MASTER_I2C_ARB_LOST |
                                                    I2CM_INTR_MASTER_I2C_BUS_ERROR);
        
        /* Reset block in case of: LOST_ARB or BUS_ERR */
        if(0u != enableInterrupts)
        {
            enableInterrupts = CyEnterCriticalSection();
            I2CM_SCB_SW_RESET;
            CyExitCriticalSection(enableInterrupts);
        }
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterSendStop
********************************************************************************
*
* Summary:
*  Generates I2C Stop condition on bus. Function do nothing if Start or Restart
*  condition was failed before call this function.
*
* Parameters:
*  None
*
* Return:
*  Status error - zero means no errors.
*
* Side Effects:
*  The Stop generation is required to complete transaction.
*  This function does not wait while Stop condition will be generated.
*
* Global variables:
*  I2CM_state - used to store current state of software FSM.
*
*******************************************************************************/
uint32 I2CM_I2CMasterSendStop(void)
{
    uint32 errStatus;
    uint8  enableInterrupts;

    errStatus        = I2CM_I2C_MSTR_NOT_READY;
    enableInterrupts = 0u;

    /* Check FSM state before generate Stop condition */
    if(I2CM_CHECK_I2C_MASTER_ACTIVE)
    {
        /*
        * Write direction: generates Stop
        * Read  direction: generates NACK and Stop
        */
        I2CM_I2C_MASTER_GENERATE_STOP;

        while(!I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_STOP     |
                                                  I2CM_INTR_MASTER_I2C_ARB_LOST |
                                                  I2CM_INTR_MASTER_I2C_BUS_ERROR))
        {
            /* Wait until Stop will be generated */
        }

        /* 
        * Check what was actually generated.
        *  LOST_ARB - NACK generation: the other master can drive ACK.
        *           - Misplaced Start while NACK generation.
        *           - Undefiend lost arbitration conditions.
        *  BUS_ERR  - added just in case undefined lost arbitration.
        *  Reset SCB on either LOST_ARB or BUS_ERR as both could be caused by
        *  misplaced Start event to reset bus busy.
        */  
        if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_STOP))
        {
            errStatus = I2CM_I2C_MSTR_NO_ERROR;
        }
        else if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ARB_LOST))
        {
                         errStatus = I2CM_I2C_MSTR_ERR_ARB_LOST;
                  enableInterrupts = I2CM_I2C_RESET_ERROR;
        }
        else /* I2CM_INTR_MASTER_I2C_BUS_ERROR set is else condition */
        {
                         errStatus = I2CM_I2C_MSTR_ERR_BUS_ERR;
                  enableInterrupts = I2CM_I2C_RESET_ERROR;
        }
        
        I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_I2C_STOP     |
                                                    I2CM_INTR_MASTER_I2C_ARB_LOST |
                                                    I2CM_INTR_MASTER_I2C_BUS_ERROR);
        
        /* Reset block in case of: LOST_ARB or BUS_ERR */
        if(0u != enableInterrupts)
        {
            enableInterrupts = CyEnterCriticalSection();
            I2CM_SCB_SW_RESET;
            CyExitCriticalSection(enableInterrupts);
        }
        
        I2CM_state = I2CM_I2C_FSM_IDLE;
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterWriteByte
********************************************************************************
*
* Summary:
*  Sends one byte to a slave. A valid Start or ReStart condition must be
*  generated before this call this function. Function do nothing if Start or
*  Restart condition was failed before call this function.
*
* Parameters:
*  data:  The data byte to send to the slave.
*
* Return:
*  Status error - zero means no errors.
*
* Side Effects:
*  This function is entered without a 'byte complete' bit set in the I2C_CSR
*  register. It does not exit until it will be set.
*
* Global variables:
*  I2CM_state - used to store current state of software FSM.
*
*******************************************************************************/
uint32 I2CM_I2CMasterWriteByte(uint32 theByte)
{
    uint32 errStatus;
    uint8  enableInterrupts;

    errStatus        = I2CM_I2C_MSTR_NOT_READY;
    enableInterrupts = 0u;

    /* Check FSM state before write byte */
    if(I2CM_CHECK_I2C_MASTER_ACTIVE)
    {
        I2CM_TX_FIFO_WR_REG = theByte;

        while(!I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ACK      |
                                                  I2CM_INTR_MASTER_I2C_NACK     |
                                                  I2CM_INTR_MASTER_I2C_ARB_LOST | 
                                                  I2CM_INTR_MASTER_I2C_BUS_ERROR))
        {
            /* Wait until byte will be transfered */
        }

        /*
        * Check results after byte was sent.
        *  LOST_ARB - SDA line is not match to what master drives: 
        *  lost arbitration or misplaced Start. Place: 8-bits of data.
        *  The misplaced Start is possible when SCB drives SDA 1 and it changes to 0, when SCL is 1.
        *  BUS_ERR - misplaced Start or Stop when Slave drives. Place: ACK/NACK bit.
        *  The misplaced Start or Stop causes the bus idle status to get stuck to busy.
        *  The misplaced Start is possible when SCB drives SCL 1 and it changes 
        *  from 1 to 0 (Start) or 0 to 1 (Stop).
        *  Reset SCB on either LOST_ARB or BUS_ERR as both could be caused by
        *  misplaced Start event to reset bus busy.
        */
        if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ACK))
        {
            I2CM_state = I2CM_I2C_FSM_MSTR_HALT;
                         errStatus = I2CM_I2C_MSTR_NO_ERROR;
        }
        else if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_NACK))
        {
            I2CM_state = I2CM_I2C_FSM_MSTR_HALT;
                         errStatus = I2CM_I2C_MSTR_ERR_LB_NAK;
        }
        else if(I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ARB_LOST))
        {
            I2CM_state = I2CM_I2C_FSM_IDLE;
                         errStatus = I2CM_I2C_MSTR_ERR_ARB_LOST;
                  enableInterrupts = I2CM_I2C_RESET_ERROR;
        }
        else /* I2CM_INTR_MASTER_I2C_BUS_ERROR set is else condition */
        {
            I2CM_state = I2CM_I2C_FSM_IDLE;
                         errStatus = I2CM_I2C_MSTR_ERR_BUS_ERR;
                  enableInterrupts = I2CM_I2C_RESET_ERROR;
        }

        I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_I2C_ACK      |
                                                    I2CM_INTR_MASTER_I2C_NACK     |
                                                    I2CM_INTR_MASTER_I2C_ARB_LOST |
                                                    I2CM_INTR_MASTER_I2C_BUS_ERROR);
        
        /* Reset block in case of: LOST_ARB or BUS_ERR */
        if(0u != enableInterrupts)
        {
            enableInterrupts = CyEnterCriticalSection();
            I2CM_SCB_SW_RESET;
            CyExitCriticalSection(enableInterrupts);
        }
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterReadByte
********************************************************************************
*
* Summary:
*  Reads one byte from a slave and ACK or NACK the transfer. A valid Start or
*  ReStart condition must be generated before this call this function. Function
*  do nothing if Start or Restart condition was failed before call this
*  function.
*
* Parameters:
*  acknNack:  Zero, response with NACK, if non-zero response with ACK.
*
* Return:
*  Byte read from slave.
*
* Side Effects:
*  This function is entered without a 'byte complete' bit set in the I2C_CSR
*  register. It does not exit until it will be set.
*
* Global variables:
*  I2CM_state - used to store current state of software FSM.
*
*******************************************************************************/
uint32 I2CM_I2CMasterReadByte(uint32 ackNack)
{
    uint32 theByte;
    uint8 enableInterrupts;

    /* Return invelid byte in case BUS_ERR was happen while receiving */
    theByte = I2CM_I2C_INVALID_BYTE;

    /* Check FSM state before read byte */
    if(I2CM_CHECK_I2C_MASTER_ACTIVE)
    {
        while((!I2CM_CHECK_INTR_RX(I2CM_INTR_RX_NOT_EMPTY)) &&
              (!I2CM_CHECK_INTR_MASTER(I2CM_INTR_MASTER_I2C_ARB_LOST | 
                                                  I2CM_INTR_MASTER_I2C_BUS_ERROR)))
        {
            /* Wait until byte will be received */
        }

        /*
        * Check results after byte was sent.
        *  RX_NOT_EMPTY - the one byte is succesfully received.
        *  LOST_ARB - added just in case because master drives ACK only: level 0 on the bus.
        *  NACK is driven by separate API.
        *  BUS_ERR - misplaced Start or Stop when Slave drives. Place: 8 data bits.
        *  The misplaced Start or Stop causes the bus idle status to get stuck to busy.
        *  The misplaced Start is possible when SCB drives SCL 1 and it changes 
        *  from 1 to 0 (Start) or 0 to 1 (Stop).
        *  Reset SCB on either LOST_ARB or BUS_ERR as both could be caused by
        *  misplaced Start event to reset bus busy.
        */
        if(I2CM_CHECK_INTR_RX(I2CM_INTR_RX_NOT_EMPTY))
        {
            theByte = I2CM_RX_FIFO_RD_REG;

            I2CM_ClearRxInterruptSource(I2CM_INTR_RX_NOT_EMPTY);

            /* 
            * ACK  - generates directly by master CMD.
            * NACK - does nothing. The NACK and STOP are generated by I2CM_MasterSendStop() 
            */
            if(0u == ackNack)  /* Do ACK */
            {
                I2CM_I2C_MASTER_GENERATE_ACK;
            }
            else /* Do nothing */
            {
                I2CM_state = I2CM_I2C_FSM_MSTR_HALT;
            }
        }
        else
        {
            I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_ALL);
        
            /* Reset block in case of: LOST_ARB or BUS_ERR */
            enableInterrupts = CyEnterCriticalSection();
            I2CM_SCB_SW_RESET;
            CyExitCriticalSection(enableInterrupts);
        }
    }

    return(theByte);
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterGetReadBufSize
********************************************************************************
*
* Summary:
*  Returns the amount of bytes that has been transferred with an
*  I2C_MasterReadBuf command.
*
* Parameters:
*  None
*
* Return:
*  Byte count of transfer. If the transfer is not yet complete, it will return
*  the byte count transferred so far.
*
* Global variables:
*  I2CM_mstrRdBufIndex - used to current index within master read
*  buffer.
*
*******************************************************************************/
uint32 I2CM_I2CMasterGetReadBufSize(void)
{
    return(I2CM_mstrRdBufIndex);
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterGetWriteBufSize
********************************************************************************
*
* Summary:
*  Returns the amount of bytes that has been transferred with an
*  I2C_MasterWriteBuf command.
*
* Parameters:
*  None
*
* Return:
*  Byte count of transfer. If the transfer is not yet complete, it will return
*  the byte count transferred so far.
*
* Global variables:
*  I2CM_mstrWrBufIndex - used to current index within master write
*  buffer.
*
*******************************************************************************/
uint32 I2CM_I2CMasterGetWriteBufSize(void)
{
    return(I2CM_mstrWrBufIndex);
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterClearReadBuf
********************************************************************************
*
* Summary:
*  Resets the read buffer pointer back to the first byte in the buffer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  I2CM_mstrRdBufIndex - used to current index within master read
*   buffer.
*  I2CM_mstrStatus - used to store current status of I2C Master.
*
*******************************************************************************/
void I2CM_I2CMasterClearReadBuf(void)
{
    I2CM_mstrRdBufIndex = 0u;
    I2CM_mstrStatus    &= (uint16) ~I2CM_I2C_MSTAT_RD_CMPLT;
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterClearWriteBuf
********************************************************************************
*
* Summary:
*  Resets the write buffer pointer back to the first byte in the buffer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  I2CM_mstrRdBufIndex - used to current index within master read
*   buffer.
*  I2CM_mstrStatus - used to store current status of I2C Master.
*
*******************************************************************************/
void I2CM_I2CMasterClearWriteBuf(void)
{
    I2CM_mstrWrBufIndex = 0u;
    I2CM_mstrStatus    &= (uint16) ~I2CM_I2C_MSTAT_WR_CMPLT;
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterStatus
********************************************************************************
*
* Summary:
*  Returns the master's communication status.
*
* Parameters:
*  None
*
* Return:
*  Current status of I2C master.
*
* Global variables:
*  I2CM_mstrStatus - used to store current status of I2C Master.
*
*******************************************************************************/
uint32 I2CM_I2CMasterStatus(void)
{
    uint32 status;

    status = (uint32) I2CM_mstrStatus;

    if(I2CM_CHECK_I2C_MASTER_ACTIVE)
    {
        /* Add status of master pending tranaction: MSTAT_XFER_INP */
        status |= (uint32) I2CM_I2C_MSTAT_XFER_INP;
    }

    return(status);
}


/*******************************************************************************
* Function Name: I2CM_I2CMasterClearStatus
********************************************************************************
*
* Summary:
*  Clears all status flags and returns the master status.
*
* Parameters:
*  None
*
* Return:
*  Current status of I2C master.
*
* Global variables:
*  I2CM_mstrStatus - used to store current status of I2C Master.
*
*******************************************************************************/
uint32 I2CM_I2CMasterClearStatus(void)
{
    uint32 status;

    /* Read and clear master status */
    status = (uint32) I2CM_mstrStatus;
    I2CM_mstrStatus = I2CM_I2C_MSTAT_CLEAR;

    return(status);
}



/*******************************************************************************
* Function Name: I2CM_I2CReStartWorkaround
********************************************************************************
*
* Summary:
*  Generates ReStart condition:
*   1. write, Restart: when txfifo empty (use the INTR_TX.UNDERFLOW interrupt 
*      to trigger), slave stretch SCL re-enable SCB and set I2C_M_CMD.START 
*      (for SCB FSM, it is START; for external I2C bus, it is RESTART).
*
*   2. read, Restart: when expected data bytes received, SCL drives NACK
*      use GPIO mode of the pin. The SCL remain low while block re-enable
*      and set I2C_M_CMD.START. The SCL data register is chnged to 1 at the 
*      end. (for SCB FSM, it is START; for external I2C bus, it is RESTART).
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  The NACK generation by GPIO causes greater SCL period.
*
* Note:
*  The SCB IP re-enable has no effect on master CMD_M_START.
*
*******************************************************************************/
void I2CM_I2CReStartGeneration(void)
{    
    if(I2CM_CHECK_I2C_STATUS(I2CM_I2C_STATUS_M_READ))
    {
        I2CM_SET_I2C_SCL_DR(I2CM_I2C_SCL_LOW);
        
        /* Switch HSIOM to GPIO */
        I2CM_SET_I2C_SCL_HSIOM_SEL(I2CM_HSIOM_GPIO_SEL);
                                       
        /* Disable SCB block */
        I2CM_CTRL_REG &= (uint32) ~I2CM_CTRL_ENABLED;
                
        I2CM_SET_I2C_SCL_DR(I2CM_I2C_SCL_LOW);
        CyDelayUs(I2CM_I2C_TLOW_TIME);  /* Count tHIGH */
        
        I2CM_SET_I2C_SCL_DR(I2CM_I2C_SCL_HIGH);
        CyDelayUs(I2CM_I2C_THIGH_TIME); /* Count tHIGH */
        
        I2CM_SET_I2C_SCL_DR(I2CM_I2C_SCL_LOW);
        CyDelayUs(I2CM_I2C_TLOW_TIME);  /* Count tLOW */
        
        /* Enable SCB block */
        I2CM_CTRL_REG |= (uint32) I2CM_CTRL_ENABLED;
        
        /* Switch HSIOM to I2C */
        I2CM_SET_I2C_SCL_HSIOM_SEL(I2CM_HSIOM_I2C_SEL);
        
        /* Set command for Start generation */
        I2CM_I2C_MASTER_CMD_REG = I2CM_I2C_MASTER_CMD_M_START;
        
        I2CM_SET_I2C_SCL_DR(I2CM_I2C_SCL_LOW);
    }
    else
    {
        I2CM_SET_I2C_SCL_DR(I2CM_I2C_SCL_LOW);
        
        /* Re-enable SCB block: this resets part of functions */
        I2CM_SCB_SW_RESET;
       
        /* Generate ReStart when bus becomes IDLE: the SCB waits in HW until IDLE. 
        * The START CMD is not effected by SCB IP re-enable.
        */
        I2CM_I2C_MASTER_CMD_REG = I2CM_I2C_MASTER_CMD_M_START;
        
        I2CM_SET_I2C_SCL_DR(I2CM_I2C_SCL_HIGH);
    }
}

#endif /* (I2CM_I2C_MASTER_CONST) */


/* [] END OF FILE */
