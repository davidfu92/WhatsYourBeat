from time import sleep
import serial
import time
import thread
import pymedia.audio.sound as sound

beat = 0

# Define a function for the thread
def calc_rate(threadName, delay):
        while 1:
                time.sleep(delay)
                print "HeartBeat: %s" % (float(beat) / 60)
                beat = 0

# Create two threads as follows
try:
        thread1 = thread.start_new_thread(calc_rate, ("Calc", 61))
except:
        print "Error: unable to start thread"


ser = serial.Serial('COM6', 9600) # Establish the connection on a specific port


text=open('beat.txt','w')
while 1:
	str=ser.readline()
	if int(str) > 0:
                beat = beat + 1
        text.write(str)
        # print(str)
