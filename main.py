# -*- coding: utf-8 -*-
import robot
import time
r = robot.Robot()
r.connect('COM11', None)
try:
    r.init()
    time.sleep(1)
    while True:
        val=int(input('val= '))
        r.setJoint('j1',val)
except:
    raise Exception("Error!")
r.close()
