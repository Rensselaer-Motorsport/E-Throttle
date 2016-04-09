'''
This is just for testing purposes, it's pretty ugly and hacky
'''

import sys, time, random
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
        self.label_map['TPSA'] = self.tps1_val_label
        self.label_map['TPSB'] = self.tps2_val_label
        self.label_map['APPA'] = self.apps1_val_label
        self.label_map['APPB'] = self.apps2_val_label
        self.label_map['BRAK'] = self.brake_val_label

        self.start_threads()

        self.show()

    def update_vals(self, update_map):
        for s in update_map.keys():
            self.label_map[s].setText(str(update_map[s]))

    # def update_text(self, i):
    #     self.tps1_val_label.setText(str(i['a']))

    def start_threads(self):
        self.threads = []              # this will keep a reference to threads
        thread = ReadSerialThread(self)    # create a thread
        thread.trigger.connect(self.update_vals)  # connect to it's signal
        # thread.setup(i)            # just setting up a parameter
        thread.start()             # start the thread
        self.threads.append(thread) # keep a reference



class ReadSerialThread(QThread):
    trigger = pyqtSignal(dict)

    def __init__(self, parent=None):
        super(ReadSerialThread, self).__init__(parent)

    def run(self):
        count = 0
        while True:
            time.sleep(0.005)
            self.trigger.emit(self.get_updates())

    def get_updates(self):
        updates = {}
        updates['TPSA'] = int(10*random.random())
        updates['TPSB'] = int(10*random.random())
        updates['APPA'] = int(10*random.random())
        updates['APPB'] = int(10*random.random())
        updates['BRAK'] = int(10*random.random())
        return updates


def main():
    app = QApplication(sys.argv)
    mw = GUI_window()
    # thread = AThread()
    # thread.finished.connect(app.exit)
    # thread.start()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
