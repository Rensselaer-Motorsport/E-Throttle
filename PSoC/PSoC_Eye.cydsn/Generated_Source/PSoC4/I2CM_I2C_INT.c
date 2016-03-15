/*******************************************************************************
* File Name: I2CM_I2C_INT.c
* Version 1.0
*
* Description:
*  This file provides the source code to the Interrupt Servive Routine for
*  the SCB Component in I2C mode.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2CM_PVT.h"
#include "I2CM_I2C_PVT.h"


/*******************************************************************************
* Function Name: I2CM_I2C_ISR
********************************************************************************
*
* Summary:
*  Handles Interrupt Service Routine for SCB I2C mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(I2CM_I2C_ISR)
{
    uint32 diffCount;
    uint32 endTransfer;
    uint8 enableInterrupts;

    #if(I2CM_CHECK_I2C_ACCEPT_ADDRESS_CONST)
        uint32 address;
    #endif /* (I2CM_CHECK_I2C_ACCEPT_ADDRESS_CONST) */

    endTransfer = 0u; /* Continue active transfer */
    
    /* Call customer routine if registered */
    if(NULL != I2CM_customIntrHandler)
    {
        I2CM_customIntrHandler();
    }

    if(I2CM_CHECK_INTR_I2C_EC_MASKED(I2CM_INTR_I2C_EC_WAKE_UP))
    {
        /* Mask-off after wakeup */
        I2CM_SetI2CExtClkInterruptMode(I2CM_NO_INTR_SOURCES);
    }

    /* Master and Slave error tracking: 
    * Add master state check to track only master errors when master is active or track 
    * slave errors when slave active or idle.
    * Specil MMS case: on address phase with misplaced Start: master sets LOST_ARB and 
    * slave BUS_ERR. The valid event is LOST_ARB from master.
    */
    if(I2CM_CHECK_I2C_FSM_MASTER)
    {        
        #if(I2CM_I2C_MASTER)
        {
            /* INTR_MASTER_I2C_BUS_ERROR:
            * Misplaced Start or Stop condition was occurred on the bus: complete transaction.
            * The interrupt is cleared in the I2C_FSM_EXIT_IDLE.
            */
            if(I2CM_CHECK_INTR_MASTER_MASKED(I2CM_INTR_MASTER_I2C_BUS_ERROR))
            {
                I2CM_mstrStatus |= (uint16) (I2CM_I2C_MSTAT_ERR_XFER |
                                                         I2CM_I2C_MSTAT_ERR_BUS_ERROR);

                endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER;
            }

            /* INTR_MASTER_I2C_ARB_LOST:
            * MultiMaster lost arbitrage while transaction: complete transaction.
            * Misplaced Start or Stop condition treats as lost arbitration when master drives SDA. 
            * The interrupt is cleared in the I2C_FSM_EXIT_IDLE.
            */
            if(I2CM_CHECK_INTR_MASTER_MASKED(I2CM_INTR_MASTER_I2C_ARB_LOST))
            {
                I2CM_mstrStatus |= (uint16) (I2CM_I2C_MSTAT_ERR_XFER |
                                                         I2CM_I2C_MSTAT_ERR_ARB_LOST);
                
                endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER;
            }

            #if(I2CM_I2C_MULTI_MASTER_SLAVE)
            {
                /* I2C_MASTER_CMD_M_START_ON_IDLE: 
                * MultiMaster-Slave does not generate start, because Slave was addressed 
                * earlier: pass control the slave FSM.
                */
                if(I2CM_CHECK_I2C_MASTER_CMD(I2CM_I2C_MASTER_CMD_M_START_ON_IDLE))
                {
                    I2CM_mstrStatus |= (uint16) (I2CM_I2C_MSTAT_ERR_XFER |
                                                             I2CM_I2C_MSTAT_ERR_ABORT_XFER);

                    endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER;
                }
            }
            #endif

            /* Error handling common part: 
            * Set completion flag of master transcation and pass control to:
            *  - I2C_FSM_EXIT_IDLE - to complete transcation in case of: ARB_LOST or BUS_ERR.
            *  - I2C_FSM_IDLE      - to take chanse for slave to process incomming transcation.
            */
            if(0u != endTransfer)
            {
                /* Set completion before FSM change */
                I2CM_mstrStatus |= (uint16) I2CM_GET_I2C_MSTAT_CMPLT;
                                
                #if(I2CM_I2C_MULTI_MASTER_SLAVE)
                {
                    if(I2CM_CHECK_I2C_FSM_ADDR)
                    {
                        /* The Start generation was set after enother master start accessing the Slave.
                        * Clean-up the master and turn to slave. Set state to IDLE.
                        */
                        if(I2CM_CHECK_I2C_MASTER_CMD(I2CM_I2C_MASTER_CMD_M_START_ON_IDLE))
                        {
                            I2CM_I2C_MASTER_CLEAR_START;
                            
                            endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER; /* Pass control to Slave */
                        }
                        /* The valid arbitration lost on address phase happens only when: master LOST_ARB set and 
                        * slave BUS_ERR is cleared. Only in that case set state to IDLE without SCB IP re-enable.
                        */
                        else if((!I2CM_CHECK_INTR_SLAVE_MASKED(I2CM_INTR_SLAVE_I2C_BUS_ERROR))
                               && I2CM_CHECK_INTR_MASTER_MASKED(I2CM_INTR_MASTER_I2C_ARB_LOST))
                        {
                            endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER; /* Pass control to Slave */
                        }
                        else
                        {
                            endTransfer = 0u; /* Causes I2C_FSM_EXIT_IDLE to be set below */
                        }
                        
                        if(0u != endTransfer) /* Clean-up master to proceed with slave */
                        {
                            I2CM_CLEAR_TX_FIFO; /* Shifter keeps address, clear it */
                            
                            I2CM_DISABLE_MASTER_AUTO_DATA_ACK; /* In case of reading disable autoACK */
                            
                            /* Clean-up master interrupt sources */
                            I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_ALL);
                            
                            /* Disable data processing interrupts: they should be cleared before */
                            I2CM_SetRxInterruptMode(I2CM_NO_INTR_SOURCES);
                            I2CM_SetTxInterruptMode(I2CM_NO_INTR_SOURCES);

                            I2CM_state = I2CM_I2C_FSM_IDLE;
                        }
                        else
                        {
                            /* Set I2C_FSM_EXIT_IDLE for BUS_ERR and ARB_LOST (that is really bus error) */
                            I2CM_state = I2CM_I2C_FSM_EXIT_IDLE;
                        }
                    }
                    else
                    {
                        /* Set I2C_FSM_EXIT_IDLE if any other state than address */
                        I2CM_state = I2CM_I2C_FSM_EXIT_IDLE;
                    }
                }
                #else
                {
                    /* In case of LOST*/
                    I2CM_state = I2CM_I2C_FSM_EXIT_IDLE;
                }
                #endif
            }
        }
        #endif
    }
    else /* (I2CM_CHECK_I2C_FSM_SLAVE) */
    {
        #if(I2CM_I2C_SLAVE)
        {
            /* INTR_SLAVE_I2C_BUS_ERROR or I2CM_INTR_SLAVE_I2C_ARB_LOST:
            * Misplaced Start or Stop condition was occurred on the bus: set flag
            * to notify error condition.
            */
            if(I2CM_CHECK_INTR_SLAVE_MASKED(I2CM_INTR_SLAVE_I2C_BUS_ERROR |
                                                        I2CM_INTR_SLAVE_I2C_ARB_LOST))
            {
                if(I2CM_CHECK_I2C_FSM_RD)
                {
                    /* TX direction: master reads from slave */
                    I2CM_slStatus &= (uint8) ~I2CM_I2C_SSTAT_RD_BUSY;
                    I2CM_slStatus |= (uint8) (I2CM_I2C_SSTAT_RD_ERR | 
                                                          I2CM_I2C_SSTAT_RD_CMPLT);
                }
                else
                {
                    /* RX direction: master writes into slave */
                    I2CM_slStatus &= (uint8) ~I2CM_I2C_SSTAT_WR_BUSY;
                    I2CM_slStatus |= (uint8) (I2CM_I2C_SSTAT_WR_ERR |
                                                          I2CM_I2C_SSTAT_WR_CMPLT);
                }

                I2CM_state = I2CM_I2C_FSM_EXIT_IDLE;
            }
        }
        #endif
    }    

    /* States description:
    * Any Master operation starts from: ADDR_RD/WR state as the master generates traffic on the bus.
    * Any Slave operation starts from: IDLE state as slave always waiting actions from the master.
    */

    /* FSM Master */
    if(I2CM_CHECK_I2C_FSM_MASTER)
    {
        #if(I2CM_I2C_MASTER)
        {
            /* INTR_MASTER_I2C_STOP: 
            * Stop condition was generated by the master: end of transction.
            * Set completion flags to notify API.
            */
            if(I2CM_CHECK_INTR_MASTER_MASKED(I2CM_INTR_MASTER_I2C_STOP))
            {
                I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_I2C_STOP);

                I2CM_mstrStatus |= (uint16) I2CM_GET_I2C_MSTAT_CMPLT;
                I2CM_state       = I2CM_I2C_FSM_IDLE;
            }
            else
            {
                if(I2CM_CHECK_I2C_FSM_ADDR) /* Address stage */
                {
                    /* INTR_MASTER_I2C_NACK:
                    * Master send address but it was NACKed by the slave: complete transaction. 
                    */
                    if(I2CM_CHECK_INTR_MASTER_MASKED(I2CM_INTR_MASTER_I2C_NACK))
                    {   
                        I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_I2C_NACK);
                        
                        I2CM_mstrStatus |= (uint16) (I2CM_I2C_MSTAT_ERR_XFER |
                                                                 I2CM_I2C_MSTAT_ERR_ADDR_NAK);

                        endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER;
                    }
                    /* INTR_TX_UNDERFLOW. The address byte was sent:
                    *  - TX direction: the clock is stretched after ACK phase, because TX FIFO is
                    *    EMPTY. The TX EMPTY clean all TX interrupt sources.
                    *  - RX direction: the 1st byte is receiving, but there is no ACK permision,
                    *    clock is stretched after 1 byte will be received.
                    */
                    else
                    {
                        if(I2CM_CHECK_I2C_FSM_RD) /* Reading */
                        {
                            I2CM_state = I2CM_I2C_FSM_MSTR_RD_DATA;
                        }
                        else /* Writing */
                        {
                            I2CM_state = I2CM_I2C_FSM_MSTR_WR_DATA;
                            I2CM_SetTxInterruptMode(I2CM_INTR_TX_EMPTY);
                        }
                    }
                }

                if(I2CM_CHECK_I2C_FSM_DATA) /* Data phase */
                {
                    if(I2CM_CHECK_I2C_FSM_RD) /* Reading */
                    {
                        /* INTR_RX_FULL:
                        * RX direction: master received 8 bytes, the 9th byte is receiving.
                        * Get data from RX FIFO and decide whether to ACK or  NACK following bytes.
                        */
                        if(I2CM_CHECK_INTR_RX_MASKED(I2CM_INTR_RX_FULL))
                        {
                            /* Calculate difference */
                            diffCount =  I2CM_mstrRdBufSize -
                                        (I2CM_mstrRdBufIndex + I2CM_GET_RX_FIFO_ENTRIES);

                            /* Proceed transaction or end it when RX FIFO
                             * become FULL again .
                            */
                            if(diffCount > I2CM_FIFO_SIZE)
                            {
                                diffCount = I2CM_FIFO_SIZE;
                            }
                            else
                            {
                                if(0u == diffCount)
                                {
                                    I2CM_DISABLE_MASTER_AUTO_DATA_ACK;

                                    diffCount   = I2CM_FIFO_SIZE;
                                    endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER;
                                }
                            }

                            for(;(0u != diffCount);diffCount--)
                            {
                                I2CM_mstrRdBufPtr[I2CM_mstrRdBufIndex] = (uint8)
                                                                                        I2CM_RX_FIFO_RD_REG;
                                I2CM_mstrRdBufIndex++;
                            }
                        }
                        /* INTR_RX_NOT_EMPTY: 
                        * RX direction: master received one data byte need to ACK or NACK.
                        * The last byte is stored and NACKed by the master. The NACK and Stop is
                        * generated by one command generate Stop.
                        */
                        else if(I2CM_CHECK_INTR_RX_MASKED(I2CM_INTR_RX_NOT_EMPTY))
                        {
                            /* Put data in the component buffer */
                            I2CM_mstrRdBufPtr[I2CM_mstrRdBufIndex] = (uint8) I2CM_RX_FIFO_RD_REG;
                            I2CM_mstrRdBufIndex++;

                            if(I2CM_mstrRdBufIndex < I2CM_mstrRdBufSize)
                            {
                                I2CM_I2C_MASTER_GENERATE_ACK;
                            }
                            else
                            {
                               endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER;
                            }
                        }
                        else
                        {
                            /* Does nothing */
                        }

                        I2CM_ClearRxInterruptSource(I2CM_INTR_RX_ALL);
                    }
                    else /* Writing */
                    {
                        /* INTR_MASTER_I2C_NACK :
                        * Master writes data to the slave and NACK was received: not all bytes were
                        * written to the slave from TX FIFO. Revert index if there is data in
                        * TX FIFO and pass control to complete transfer.
                        */
                        if(I2CM_CHECK_INTR_MASTER_MASKED(I2CM_INTR_MASTER_I2C_NACK))
                        {
                            I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_I2C_NACK);

                            /* Rollback the write buffer index: the NACKed byte remains in the shifter */
                            I2CM_mstrWrBufIndexTmp -= (I2CM_GET_TX_FIFO_ENTRIES +
                                                                   I2CM_GET_TX_FIFO_SR_VALID);

                            /* Update number of transfered bytes */
                            I2CM_mstrWrBufIndex = I2CM_mstrWrBufIndexTmp;

                            I2CM_mstrStatus |= (uint16) (I2CM_I2C_MSTAT_ERR_XFER |
                                                                     I2CM_I2C_MSTAT_ERR_SHORT_XFER);

                            I2CM_CLEAR_TX_FIFO;

                            endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER;
                        }
                        /* INTR_TX_EMPTY :
                        * TX direction: the TX FIFO is EMPTY, the data from buffer need be put there.
                        * When there is no data in the component buffer, underflow interrupt is
                        * enabled to catch when all data will be transfered.
                        */
                        else if(I2CM_CHECK_INTR_TX_MASKED(I2CM_INTR_TX_EMPTY))
                        {
                            while(I2CM_FIFO_SIZE != I2CM_GET_TX_FIFO_ENTRIES)
                            {
                                /* The temporary mstrWrBufIndexTmp is used because slave could NACK the byte and index
                                * roll-back required in this case. The mstrWrBufIndex is updated at the end of transfer
                                */
                                if(I2CM_mstrWrBufIndexTmp < I2CM_mstrWrBufSize)
                                {
                                    /* Put data into TX FIFO */
                                    I2CM_TX_FIFO_WR_REG = (uint32) I2CM_mstrWrBufPtr[I2CM_mstrWrBufIndexTmp];
                                    I2CM_mstrWrBufIndexTmp++;
                                }
                                else
                                {
                                    break; /* No more data to put */
                                }
                            }

                            if(I2CM_mstrWrBufIndexTmp == I2CM_mstrWrBufSize)
                            {
                                I2CM_SetTxInterruptMode(I2CM_INTR_TX_UNDERFLOW);
                            }

                            I2CM_ClearTxInterruptSource(I2CM_INTR_TX_ALL);
                        }
                        /* INTR_TX_UNDERFLOW:
                        * TX direction: all data from TX FIFO was transfered to the slave.
                        * The transaction need to be completed.
                        */
                        else if(I2CM_CHECK_INTR_TX_MASKED(I2CM_INTR_TX_UNDERFLOW))
                        {
                            /* Update number of transfered bytes */
                            I2CM_mstrWrBufIndex = I2CM_mstrWrBufIndexTmp;
                            
                            endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER;
                        }
                        else
                        {
                            /* Does nothing */
                        }
                    }
                }

                if(0u != endTransfer) /* Complete transfer */
                {
                    /* Clean-up master after reading: only in case of NACK */
                    I2CM_DISABLE_MASTER_AUTO_DATA_ACK;
                    
                    /* Disable data processing interrupts: they should be cleared before */
                    I2CM_SetRxInterruptMode(I2CM_NO_INTR_SOURCES);
                    I2CM_SetTxInterruptMode(I2CM_NO_INTR_SOURCES);

                    if(I2CM_CHECK_I2C_MODE_NO_STOP(I2CM_mstrControl))
                    {
                        /* On-going transaction is suspend: the ReStart is generated by API request */
                        I2CM_mstrStatus |= (uint16) (I2CM_I2C_MSTAT_XFER_HALT |
                                                                 I2CM_GET_I2C_MSTAT_CMPLT);

                        I2CM_state = I2CM_I2C_FSM_MSTR_HALT;
                    }
                    else
                    {
                        /* Complete transaction: exclude data processing state and generate Stop.
                        * The completion status will be set after Stop generation.
                        * Specail case is read: because NACK and Stop is genered.
                        * The lost arbitration could occur while NACK generation
                        * (other master still reading and ACK is generated)
                        */
                        I2CM_I2C_MASTER_GENERATE_STOP;
                    }
                }
            }

        } /* (I2CM_I2C_MASTER) */
        #endif

    } /* (I2CM_CHECK_I2C_FSM_MASTER) */


    /* FSM Slave */
    else if(I2CM_CHECK_I2C_FSM_SLAVE)
    {
        #if(I2CM_I2C_SLAVE)
        {
            /* INTR_SLAVE_NACK:
            * The master completes reading the slave: the approprite flags have to be set.
            * The TX FIFO cleared after overflow condition is set.
            */
            if(I2CM_CHECK_INTR_SLAVE_MASKED(I2CM_INTR_SLAVE_I2C_NACK))
            {
                I2CM_ClearSlaveInterruptSource(I2CM_INTR_SLAVE_I2C_NACK);

                /* All entries that remain in TX FIFO max value is 9: 8 (FIFO) + 1 (SHIFTER) */
                diffCount = (I2CM_GET_TX_FIFO_ENTRIES + I2CM_GET_TX_FIFO_SR_VALID);

                if(I2CM_slOverFlowCount > diffCount) /* Overflow */
                {
                    I2CM_slStatus |= (uint8) I2CM_I2C_SSTAT_RD_OVFL;
                }
                else /* No Overflow */
                {
                    /* Roll-back the temporay index */
                    I2CM_slRdBufIndexTmp -= (diffCount - I2CM_slOverFlowCount);
                }

                /* Update slave of tranfered bytes */
                I2CM_slRdBufIndex = I2CM_slRdBufIndexTmp;
                
                /* Clean-up TX FIFO */
                I2CM_SetTxInterruptMode(I2CM_NO_INTR_SOURCES);
                I2CM_slOverFlowCount = 0u;
                I2CM_CLEAR_TX_FIFO;

                /* Complete master reading */
                I2CM_slStatus &= (uint8) ~I2CM_I2C_SSTAT_RD_BUSY;
                I2CM_slStatus |= (uint8)  I2CM_I2C_SSTAT_RD_CMPLT;
                I2CM_state     =  I2CM_I2C_FSM_IDLE;
            }


            /* INTR_SLAVE_I2C_WRITE_STOP:
            * The master completes writing to slave: the approprite flags have to be set.
            * The RX FIFO contains 1-8 bytes from previous transcation which need to be read.
            * There is possibility that RX FIFO contains address, it needs to leave it there.
            */
            if(I2CM_CHECK_INTR_SLAVE_MASKED(I2CM_INTR_SLAVE_I2C_WRITE_STOP))
            {
                I2CM_ClearSlaveInterruptSource(I2CM_INTR_SLAVE_I2C_WRITE_STOP);

                I2CM_DISABLE_SLAVE_AUTO_DATA;

                while(0u != I2CM_GET_RX_FIFO_ENTRIES)
                {
                    #if(I2CM_CHECK_I2C_ACCEPT_ADDRESS)
                    {
                        if((1u == I2CM_GET_RX_FIFO_ENTRIES) &&
                           (I2CM_CHECK_INTR_SLAVE_MASKED(I2CM_INTR_SLAVE_I2C_ADDR_MATCH)))
                        {
                            break; /* Leave address in RX FIFO */
                        }
                    }
                    #endif

                    /* Put data in the component buffer */
                    I2CM_slWrBufPtr[I2CM_slWrBufIndex] = (uint8) I2CM_RX_FIFO_RD_REG;
                    I2CM_slWrBufIndex++;
                }

                if(I2CM_CHECK_INTR_RX(I2CM_INTR_RX_OVERFLOW))
                {
                    I2CM_slStatus |= (uint8) I2CM_I2C_SSTAT_WR_OVFL;
                }

                /* Clears RX interrupt sources triggered on data receiving */
                I2CM_ClearRxInterruptSource(I2CM_INTR_RX_ALL);

                /* Complete master writing */
                I2CM_slStatus &= (uint8) ~I2CM_I2C_SSTAT_WR_BUSY;
                I2CM_slStatus |= (uint8)  I2CM_I2C_SSTAT_WR_CMPLT;
                I2CM_state     =  I2CM_I2C_FSM_IDLE;
            }


            /* INTR_SLAVE_I2C_ADDR_MATCH:
            * The address match event starts the slave operation: after leaving the TX or RX
            * direction has to chosen.
            * The wakeup interrupt must be cleared only after address match is set.
            */
            if(I2CM_CHECK_INTR_SLAVE_MASKED(I2CM_INTR_SLAVE_I2C_ADDR_MATCH))
            {
                #if(I2CM_CHECK_I2C_ACCEPT_ADDRESS) /* Address in RX FIFO */
                {
                    address  = I2CM_RX_FIFO_RD_REG;

                    /* Clears RX sources if address was received in the RX FIFO */
                    I2CM_ClearRxInterruptSource(I2CM_INTR_RX_ALL);

                    if(0u != address)
                    {
                        /* Suppress compiler warning */
                    }
                }
                #endif

                if(I2CM_CHECK_I2C_STATUS(I2CM_I2C_STATUS_S_READ))
                /* TX direction: master reads from slave */
                {
                    I2CM_SetTxInterruptMode(I2CM_INTR_TX_EMPTY);

                    /* Set temporary index to address buffer clear from API */
                    I2CM_slRdBufIndexTmp = I2CM_slRdBufIndex;

                    /* Start master reading */
                    I2CM_slStatus |= (uint8) I2CM_I2C_SSTAT_RD_BUSY;
                    I2CM_state     = I2CM_I2C_FSM_SL_RD;
                }
                else
                /* RX direction: master writes into slave */
                {
                    /* Calculate available buffer size */
                    diffCount = (I2CM_slWrBufSize - I2CM_slWrBufIndex);

                    if(diffCount < I2CM_FIFO_SIZE)
                    /* Receive data: byte-by-byte */
                    {
                        I2CM_SetRxInterruptMode(I2CM_INTR_RX_NOT_EMPTY);
                    }
                    else
                    /* Receive data: into RX FIFO */
                    {
                        if(diffCount == I2CM_FIFO_SIZE)
                        {
                            /* NACK when RX FIFO become FULL */
                            I2CM_ENABLE_SLAVE_AUTO_DATA;
                        }
                        else
                        {
                            /* Stretch clock when RX FIFO becomes FULL */
                            I2CM_ENABLE_SLAVE_AUTO_DATA_ACK;
                            I2CM_SetRxInterruptMode(I2CM_INTR_RX_FULL);
                        }
                    }

                    /* Start master reading */
                    I2CM_slStatus |= (uint8) I2CM_I2C_SSTAT_WR_BUSY;
                    I2CM_state     = I2CM_I2C_FSM_SL_WR;
                }

                /* Clear interrupts before ACK address */
                I2CM_ClearI2CExtClkInterruptSource(I2CM_INTR_I2C_EC_WAKE_UP);
                I2CM_ClearSlaveInterruptSource(I2CM_INTR_SLAVE_ALL);

                /* The preparation complete: ACK the address */
                I2CM_I2C_SLAVE_GENERATE_ACK;
            }

            /* I2CM_INTR_RX_FULL":
            * Get data from RX FIFO and decide whether to ACK or NACK following bytes 
            */
            if(I2CM_CHECK_INTR_RX_MASKED(I2CM_INTR_RX_FULL))
            {
                /* Calculate available buffer size take to account that RX FIFO is FULL */
                diffCount =  I2CM_slWrBufSize -
                            (I2CM_slWrBufIndex + I2CM_FIFO_SIZE);

                if(diffCount > I2CM_FIFO_SIZE) /* Proceed transaction */
                {
                    diffCount   = I2CM_FIFO_SIZE;
                    endTransfer = 0u;  /* Continue active transfer */
                }
                else /* End when FIFO becomes FULL again */
                {
                    endTransfer = I2CM_I2C_CMPLT_ANY_TRANSFER;
                }

                for(;(0u != diffCount);diffCount--)
                {
                    /* Put data in the component buffer */
                    I2CM_slWrBufPtr[I2CM_slWrBufIndex] = (uint8) I2CM_RX_FIFO_RD_REG;
                    I2CM_slWrBufIndex++;
                }

                if(0u != endTransfer) /* End transfer sending NACK */
                {
                    I2CM_ENABLE_SLAVE_AUTO_DATA_NACK;

                    /* The INTR_RX_FULL triggers earlier then INTR_SLAVE_I2C_STOP: 
                    * disable all RX interrupt sources.
                    */
                    I2CM_SetRxInterruptMode(I2CM_NO_INTR_SOURCES);
                }

                I2CM_ClearRxInterruptSource(I2CM_INTR_RX_FULL);
            }
            /* I2CM_INTR_RX_NOT_EMPTY: 
            * The buffer size is less than 8: it requires processing in byte-by-byte mode. 
            */
            else if(I2CM_CHECK_INTR_RX_MASKED(I2CM_INTR_RX_NOT_EMPTY))
            {
                diffCount = I2CM_RX_FIFO_RD_REG;

                if(I2CM_slWrBufIndex < I2CM_slWrBufSize)
                {
                    I2CM_I2C_SLAVE_GENERATE_ACK;

                    /* Put data into component buffer */
                    I2CM_slWrBufPtr[I2CM_slWrBufIndex] = (uint8) diffCount;
                    I2CM_slWrBufIndex++;
                }
                else /* Overflow: there is no space in the write buffer */
                {
                    I2CM_I2C_SLAVE_GENERATE_NACK;

                    I2CM_slStatus |= (uint8) I2CM_I2C_SSTAT_WR_OVFL;
                }

                I2CM_ClearRxInterruptSource(I2CM_INTR_RX_NOT_EMPTY);
            }
            else
            {
                /* Does nothing */
            }


            /* I2CM_INTR_TX_EMPTY:
            * Master reads slave: provide data to read or 0xFF in case end of the buffer
            * The overflow condition must be captured, but not set until the end of transaction.
            * There is possibility of false overflow due of TX FIFO utilization.
            */
            if(I2CM_CHECK_INTR_TX_MASKED(I2CM_INTR_TX_EMPTY))
            {
                while(I2CM_FIFO_SIZE != I2CM_GET_TX_FIFO_ENTRIES)
                {
                    /* The temporary slRdBufIndexTmp is used because master could NACK the byte and
                    * index roll-back required in this case. The slRdBufIndex is updated at the end
                    * of the read transfer.
                    */
                    if(I2CM_slRdBufIndexTmp < I2CM_slRdBufSize)
                    /* Data from buffer */
                    {
                        I2CM_TX_FIFO_WR_REG = (uint32) I2CM_slRdBufPtr[I2CM_slRdBufIndexTmp];
                        I2CM_slRdBufIndexTmp++;
                    }
                    else
                    /* Probably Overflow */
                    {
                        I2CM_TX_FIFO_WR_REG = I2CM_I2C_SLAVE_OVFL_RETURN;

                        if(0u == (I2CM_INTR_TX_OVERFLOW & I2CM_slOverFlowCount))
                        {
                            /* Get counter in range of the byte: the value 10 is overflow */
                            I2CM_slOverFlowCount++;
                        }
                    }
                }

                I2CM_ClearTxInterruptSource(I2CM_INTR_TX_EMPTY);
            }

        }  /* (I2CM_I2C_SLAVE) */
        #endif
    }


    /* FSM EXIT: 
    * Interrupt sources get here are errors: 
    * Slave:  INTR_SLAVE_I2C_BUS_ERROR, INTR_SLAVE_I2C_ARB_LOST
    * Master: INTR_MASTER_I2C_BUS_ERROR, INTR_MASTER_I2C_ARB_LOST.
    */
    else
    {
        /* Clean the Slave and Master sources before reset */
        I2CM_ClearSlaveInterruptSource(I2CM_INTR_SLAVE_ALL);
        I2CM_ClearMasterInterruptSource(I2CM_INTR_MASTER_ALL);
        
        /* Re-enable SCB block: this resets part of functions */
        enableInterrupts = CyEnterCriticalSection();
        I2CM_SCB_SW_RESET;
        CyExitCriticalSection(enableInterrupts);

        /* Clenup:
        * All other status and control bits can be cleared later.
        * Slave AUTO data ACK never happens before address ACK.
        * Slave TX and RX sources are used only after address match.
        * Master AUTO data ACK is under API control.
        * Master interrupt sources does not care after any error.
        * Master TX and RX sources are under API control.
        */

        /* Disable auto NACK before clear the FIFOs */
        I2CM_DISABLE_SLAVE_AUTO_DATA_ACK;
        I2CM_DISABLE_MASTER_AUTO_DATA_ACK;

        I2CM_SetRxInterruptMode(I2CM_NO_INTR_SOURCES);
        I2CM_SetTxInterruptMode(I2CM_NO_INTR_SOURCES);
        I2CM_ClearTxInterruptSource(I2CM_INTR_RX_ALL);
        I2CM_ClearRxInterruptSource(I2CM_INTR_TX_ALL);
        
        I2CM_state = I2CM_I2C_FSM_IDLE;
    }
}


/* [] END OF FILE */
