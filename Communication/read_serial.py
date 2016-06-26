import serial, time

class throttleReader():
    '''
        Reads in information from the E-Throttle PSoC board
    '''
    def __init__(self, comm_port):
        ''' Constructor
            Param: (string) comm_port - the serial port the PSoC board is connected to
            Return: None
        '''
        self.s = serial.Serial(baudrate=115200, port=comm_port)
        self.padbytes = 0 # Number of 'pad bytes' (0xff) that were read in a row


    def pad_recieved(self, next_byte):
        ''' Tests if a pad (i.e. 4 0xff 'pad bytes' in a row) has been recieved
            Param: (char) next_byte - the most recent byte recieved
            Return: (boolean) True if a pad has been recieved, false otherwise
        '''
        if ord(next_byte) == 0xff:
            self.padbytes += 1
            # print 'padbytes = ', self.padbytes
        else:
            self.padbytes = 0
            # print 'padbytes = ', self.padbytes
        if self.padbytes >= 4:
            self.padbytes = 0
            return True
        return False


    def wait_for_pad(self):
        ''' Waits until 4 pad bytes have been recieved
            Return: None
        '''
        pad = False
        while not pad:
            b = self.s.read()
            pad = self.pad_recieved(b)


    def get_int(self):
        ''' Gets the integer represented by the next 4 transmitted bytes
            Should be called after get_sensor()
            Return: (int) The next integer sent over the serial stream
        '''
        num = 0
        sig = 0x1
        for i in range(4):
            next_byte = ord(self.s.read())
            num += next_byte * sig
            sig *= 0x100
        return num


    def get_sensor(self):
        ''' Gets the code for the sensor label from the next 4 transmitted bytes_in
            Should be called after pad_recieved returns True
            Return: (string) The next sensor label
        '''
        label = ''
        for i in range(4):
            next_byte = self.s.read()
            label += next_byte
        return label
