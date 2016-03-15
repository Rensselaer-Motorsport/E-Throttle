/* ========================================
 *
 * The following firmware was developed by Cypress Semiconductor
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

#include <device.h>
#include "Camera.h"
#include "stdlib.h"

// Global Pan and Tilt Variables. Default value is calculated for center of Servo.
uint16 new_pan = 80, new_tilt = 80;

// Initialize Hardware
void Initialize(void)
{
	RESET_Write(0);
	CyDelay(100);
	RESET_Write(1);
	CyDelay(100);
	
	PAN_Start();
	TILT_Start();
	
	PAN_WriteCompare(new_pan);
	TILT_WriteCompare(new_tilt);
	
	I2CM_Start();
	Camera_init();
	
	CyDelay(1000);
}

// Read the current x, y values from the Camera, calculate distance to move and turn the Servo motors accordingly. 
// Faster response to align with target.
void MoveEye(uint16 x, uint16 y)
{
	// Above or below the center line?
	if (x < 512)
	{
		new_tilt = new_tilt - (abs(512 - x)/128); 	//128
	}
	else
	{
		new_tilt = new_tilt + (abs(x - 512)/128); 	//128
	}
	TILT_WriteCompare(new_tilt);					// Tilt the servo
	
	// Left or right of the center line?
	if (y < 384)
	{
		new_pan = new_pan + (abs(384 - y)/96); 		//96
	}
	else
	{
		new_pan = new_pan - (abs(y - 384)/96); 		//96
	}
	PAN_WriteCompare(new_pan);						// Pan the servo
	CyDelay(13);									// Delay for motors to settle in new location. Different for different motors and hence requires calibration.
}

// Another implementation with fixed steps.
// Lower response to align with target.
void MoveAlong(uint16 x, uint16 y)
{
	static uint16 prev_x = 0, prev_y = 0;
	
	if (abs(x - prev_x) >= 120)
	{
		if (x < prev_x)
		{new_pan = new_pan - 6;}
		else
		{new_pan = new_pan + 6;}
		prev_x = x;
		TILT_WriteCompare(new_pan);
	}
	
	if (abs(y - prev_y) >= 80)
	{
		if (y < prev_y)
		{new_tilt = new_tilt + 4;}
		else
		{new_tilt = new_tilt - 4;}
		prev_y = y;
		PAN_WriteCompare(new_tilt);
	}
}

// The main
void main()
{
    uint16 cnt = 0;
	uint8 blobs = 0;
	uint16 x = 0, y = 0;
	
	
	CyGlobalIntEnable;					// Enable all global interrupts
	
	Initialize();						// Initialize all Hardware
	
	while(1)
	{
		blobs = Camera_read();
		if (blobs & BLOB1)				// Camera can track 4 targets simultaneously. We are interested only in one.
		{
			x = Blob1.X;				// Get current x, y for the target
			y = Blob1.Y;
			
			MoveEye(x, y);				// Move the camera to bring target in center of field of vision
		}
	}
}

/* [] END OF FILE */
