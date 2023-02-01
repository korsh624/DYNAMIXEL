# -*- coding: utf-8 -*-
import robot
import time
r = robot.Robot()
r.connect('COM11', None)
try:
    r.init()
    time.sleep(1)
    while True:
        val=input('val= ').split(',')
        if val[0]=='0':
            break
        r.setJoint('j1',int(val[0]))
        r.setJoint('j2', int(val[1]))
        r.setJoint('j3',  int(val[2]))
except:
    raise Exception("Error!")
r.close()
