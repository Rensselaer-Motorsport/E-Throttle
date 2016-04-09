from buffer import *

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
