from read_serial import throttleReader

r = throttleReader('COM4')
while True:
    r.wait_for_pad()
    print r.get_int()
