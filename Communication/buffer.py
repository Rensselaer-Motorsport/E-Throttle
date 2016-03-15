from __future__ import print_function
import serial


# Parameter:    serial_in - The serial line in
# Requires:     The bytes are in order from least->most significant
# Returns:      The integer representation from the next 4 bytes
def nextInt(serial_in):
    num = 0
    sig = 0x1
    for i in range(0, 4):
        next_byte = ord(serial_in.read())
        num += next_byte * sig
        sig *= 0x100
    return num

def printNum(num):
    print ('               ', end='\r')
    print ('{0:.2f}'.format(num), end='\r')

def waitForPad(serial_in):
    num_pad_bytes = 0
    while(True):
        if num_pad_bytes == 4:
            return True
        if ord(serial_in.read()) == 0xFF:
            num_pad_bytes += 1
        else:
            num_pad_bytes = 0

s = serial.Serial(port='COM5', baudrate=115200)
pad_0 = -1
pad_1 = -2
pad_2 = -3

while(True):
    waitForPad(s)
    nextVal = nextInt(s)
    print (nextVal)
    waitForPad(s)

    #nextVal /= 40.95
    # if not((nextVal == pad_0) or (nextVal == pad_1) or (nextVal == pad_2)):
    #     printNum(nextVal)
