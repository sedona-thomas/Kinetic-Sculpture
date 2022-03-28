
   
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
    This code will accept serial sensor data  an ESP32
    @Author: Sedona Thomas
    @Date: 03/28/2022
    @Links: https://github.com/sedona-thomas/Kinetic-Sculpture
"""

import serial
import json
import re
from collections import defaultdict

class SerialCommunication(object):

    """
    The SerialCommunication tracks and updates sensor values for an ESP32 with peripherals
    :returns: returns nothing
    """

    def __init__(self):
        self.port = '/dev/cu.usbserial-023E564D'  # esp32
        self.baudrate = 115200
        self.s = serial.Serial(self.port, self.baudrate)
        self.values = defaultdict(int)

    """
    Prints current serial value
    :returns: returns nothing
    """

    def read(self):
        sensor = str(self.s.readline(), 'ascii').strip()
        print(sensor)


if __name__ == "__main__":
    display = SerialCommunication()
    while(True):
        display.read()