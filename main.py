# -*- coding: utf-8 -*-
import robot
from robot1 import date_list
import time
r = robot.Robot()
r.connect('COM6', None)
try:
    r.init()
    time.sleep(1)
    while True:
        for el in date_list:
            val=el
            if val[0]=='stop':
                break

            r.setJoint('j1',int(val[0]))
            r.setJoint('j2', int(val[1]))
            r.setJoint('j3',  int(val[2]))
            r.setJoint('j4', int(val[3]))
            r.setJoint('j5', int(val[4]))
except:
    raise Exception("Error!")
r.close()
