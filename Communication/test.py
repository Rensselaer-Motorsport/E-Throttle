import serial

s = serial.Serial(baudrate=115200, port='COM4')
while True:
    print s.read()
