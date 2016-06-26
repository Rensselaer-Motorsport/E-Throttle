'''
    This is just for testing purposes, it's pretty ugly and hacky
'''

import sys, time, random
from read_serial import throttleReader
from PyQt4.QtCore import *
from PyQt4.QtGui import *


class GUI_window(QMainWindow):
    def __init__(self):
        super(GUI_window, self).__init__()
        self.setGeometry(0, 0, 175, 260)
        self.setWindowTitle('E-throttle')

        self.tps1_label = QLabel('tps1', self)
        self.tps1_label.move(20, 20)
        self.tps2_label = QLabel('tps2', self)
        self.tps2_label.move(20, 70)
        self.apps1_label = QLabel('apps1', self)
        self.apps1_label.move(20, 120)
        self.apps2_label = QLabel('apps2', self)
        self.apps2_label.move(20, 170)
        self.brake_label = QLabel('brake', self)
        self.brake_label.move(20, 220)

        self.tps1_val_label = QLabel('0.0', self)
        self.tps1_val_label.move(100, 20)
        self.tps1_val_label.resize(40, 10)
        self.tps2_val_label = QLabel('0.0', self)
        self.tps2_val_label.move(100, 70)
        self.tps2_val_label.resize(40, 10)
        self.apps1_val_label = QLabel('0.0', self)
        self.apps1_val_label.move(100, 120)
        self.apps1_val_label.resize(40, 10)
        self.apps2_val_label = QLabel('0.0', self)
        self.apps2_val_label.move(100, 170)
        self.apps2_val_label.resize(40, 10)
        self.brake_val_label = QLabel('0.0', self)
        self.brake_val_label.move(100, 220)
        self.brake_val_label.resize(40, 10)

        self.label_map = {}
        self.label_map['TPS0'] = self.tps1_val_label
        self.label_map['TPS1'] = self.tps2_val_label
        self.label_map['APS0'] = self.apps1_val_label
        self.label_map['APS1'] = self.apps2_val_label
        self.label_map['BRAK'] = self.brake_val_label

        self.start_threads()
        self.move(100, 100)
        self.show()

    def update_vals(self, update):
        ''' Updates the value of one of the labels
            Param: update: ((String, Int)) new sensor label value pair
            Return: None
        '''
        self.label_map[update[0]].setText(str(float(update[1])/100.0))

    # def update_text(self, i):
    #     self.tps1_val_label.setText(str(i['a']))

    def start_threads(self):
        self.threads = []              # this will keep a reference to threads
        thread = ReadSerialThread(self)    # create a thread
        thread.trigger.connect(self.update_vals)  # connect to it's signal
        thread.start()             # start the thread
        self.threads.append(thread) # keep a reference


class ReadSerialThread(QThread):
    trigger = pyqtSignal(tuple)

    def __init__(self, parent=None):
        ''' Constructs a QThread that reads and processes input from the PSoC
            board
        '''
        super(ReadSerialThread, self).__init__(parent)
        self.reader = throttleReader('COM4')

    def run(self):
        ''' Main thread, will wait for a pad, then parse the input (sensor label
            and value) and send it to the GUI.
            Return: None
        '''
        count = 0
        while True:
            self.reader.wait_for_pad()
            self.trigger.emit(self.get_updates())
            # time.sleep(0.01)

    def get_updates(self):
        ''' Places the sensor label/value pair into a tuple and returns that
            Return: ((String, Int))
        '''
        sens = self.reader.get_sensor()
        val = self.reader.get_int()
        return (sens, val)


def main():
    app = QApplication(sys.argv)
    mw = GUI_window()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
