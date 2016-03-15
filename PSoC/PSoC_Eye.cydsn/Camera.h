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

#ifndef CAMERA_H
#define CAMERA_H

#include "device.h"

// bit flags for blobs
#define BLOB1 0x01
#define BLOB2 0x02
#define BLOB3 0x04
#define BLOB4 0x08

// Returned structure from a call to readSample()
struct Blob
{
   	int X;
   	int Y;
   	int Size;
   	uint8 number;
}Blob1, Blob2, Blob3, Blob4;

extern void Camera(void);
extern void Camera_init(void);   	// returns true if the connection to the sensor established correctly
extern uint8 Camera_read(void);   	// updated the blobs, and returns the number of blobs detected

// per object data
uint8 IRsensorAddress;
uint8 IRslaveAddress;
uint8 data_buf[16];
int i;
int s;

void Write_2bytes(uint8 d1, uint8 d2);
uint8 blobcount; 					// returns the number of blobs found - reads the sensor

#endif
