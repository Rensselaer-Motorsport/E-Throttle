/* ========================================
 *
 * The following firmware was ported by Cypress Semiconductor
 * PVision library for interaction with the Pixart sensor on a WiiMote
 * This work was derived from Kako's excellent Japanese website
 * http://www.kako.com/neta/2007-001/2007-001.html
 * Steve Hobley 2009 - www.stephenhobley.com
 * 
 * This work is licensed under a Creative Commons Attribution 3.0 Unported License.
 * 
 * http://creativecommons.org/licenses/by/3.0/deed.en_US
 * 
 * You are free to:
 * -To Share — to copy, distribute and transmit the work 
 * -To Remix — to adapt the work 
 * -To make commercial use of the work
 *
 * ========================================
 */

/******************************************************************************
* Includes
******************************************************************************/
#include "Camera.h"

/******************************************************************************
* Private methods
******************************************************************************/
void Write_2bytes(uint8 d1, uint8 d2)
{
	uint32 status = I2CM_I2C_MSTR_NO_ERROR;
	
	status = I2CM_I2CMasterSendStart(IRslaveAddress, 0);
	if (status != I2CM_I2C_MSTR_NO_ERROR)
	{return;}
	CyDelay(1);
    status = I2CM_I2CMasterWriteByte(d1);
	if (status != I2CM_I2C_MSTR_NO_ERROR)
	{return;}
	CyDelay(1);
	status = I2CM_I2CMasterWriteByte(d2);
	if (status != I2CM_I2C_MSTR_NO_ERROR)
	{return;}
	CyDelay(1);
    status = I2CM_I2CMasterSendStop();
	if (status != I2CM_I2C_MSTR_NO_ERROR)
	{return;}
	CyDelay(1);
}


/******************************************************************************
* Constructor
******************************************************************************/
void Camera(void)
{
	
}

/******************************************************************************
* Public methods
******************************************************************************/
// init the PVision sensor
void Camera_init(void)
{
    Blob1.number = 1;
	Blob2.number = 2;
	Blob3.number = 3;
	Blob4.number = 4;
	
	IRsensorAddress = 0xB0;
    IRslaveAddress = IRsensorAddress >> 1;			// This results in 0x21 as the address to pass to TWI
	
	I2CM_sda_SetDriveMode(I2CM_sda_DM_RES_UP);
	I2CM_scl_SetDriveMode(I2CM_scl_DM_RES_UP);
	
    // IR sensor initialize
    Write_2bytes(0x30,0x01); CyDelay(10);
    Write_2bytes(0x30,0x08); CyDelay(10);
    Write_2bytes(0x06,0x90); CyDelay(10);
    Write_2bytes(0x08,0xC0); CyDelay(10);
    Write_2bytes(0x1A,0x40); CyDelay(10);
    Write_2bytes(0x33,0x33); CyDelay(10);
    CyDelay(100);
}

uint8 Camera_read(void)
{
    uint32 status = I2CM_I2C_MSTR_NO_ERROR;
	uint8 rxdata[16] = {0};
	
	I2CM_I2CMasterClearStatus();
	
	//IR sensor read
    status = I2CM_I2CMasterSendStart(IRslaveAddress, 0);
	if (status != I2CM_I2C_MSTR_NO_ERROR)
	{return 0;}
	
    status = I2CM_I2CMasterWriteByte(0x36);
	if (status != I2CM_I2C_MSTR_NO_ERROR)
	{return 0;}
	
    status = I2CM_I2CMasterSendStop();
	if (status != I2CM_I2C_MSTR_NO_ERROR)
	{return 0;}
	
	CyDelayUs(10);
	
	status = I2CM_I2CMasterReadBuf(IRslaveAddress, &rxdata[0], 16, I2CM_I2C_MODE_COMPLETE_XFER);
	if (status != I2CM_I2C_MSTR_NO_ERROR)
	{return 0;}
	
	while(I2CM_I2CMasterStatus() != I2CM_I2C_MSTAT_RD_CMPLT);
	
    for (i=0; i<16; i++)
    {
		data_buf[i]=0;
		data_buf[i] = rxdata[i];
    }

    blobcount = 0;

    Blob1.X = data_buf[1];
    Blob1.Y = data_buf[2];
    s   = data_buf[3];
    Blob1.X += (s & 0x30) <<4;
    Blob1.Y += (s & 0xC0) <<2;
    Blob1.Size = (s & 0x0F);

    // At the moment we're using the size of the blob to determine if one is detected, either X,Y, or size could be used.
    blobcount |= (Blob1.Size < 15)? BLOB1 : 0;

    Blob2.X = data_buf[4];
    Blob2.Y = data_buf[5];
    s   = data_buf[6];
    Blob2.X += (s & 0x30) <<4;
    Blob2.Y += (s & 0xC0) <<2;
    Blob2.Size = (s & 0x0F);

    blobcount |= (Blob2.Size < 15)? BLOB2 : 0;

    Blob3.X = data_buf[7];
    Blob3.Y = data_buf[8];
    s   = data_buf[9];
    Blob3.X += (s & 0x30) <<4;
    Blob3.Y += (s & 0xC0) <<2;
    Blob3.Size = (s & 0x0F);

    blobcount |= (Blob3.Size < 15)? BLOB3 : 0;

    Blob4.X = data_buf[10];
    Blob4.Y = data_buf[11];
    s   = data_buf[12];
    Blob4.X += (s & 0x30) <<4;
    Blob4.Y += (s & 0xC0) <<2;
    Blob4.Size = (s & 0x0F);

    blobcount |= (Blob4.Size < 15)? BLOB4 : 0;

    return blobcount;
}

