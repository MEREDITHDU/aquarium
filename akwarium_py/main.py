#!/usr/bin/env python2
#-*- coding: utf8 -*-


import os, sys
import time, getopt
from avr import * 
from vusb import * 

GETTIME, SETTIME, GETTEMP, SETDATE, GETDATE, RESET, BACKLIGHT = range(7)

def main():
	v = Vusb();

	if len(sys.argv) < 2:
		print "no arg" 
		exit()

	opt = sys.argv[1].replace("\n", '')

	while True:
		print opt + ': ',

		if opt == 'time':
			print v.recv(GETTIME)
		elif opt == 'settime':
			t = time.localtime()
			timestr = "%s/%s/%s" % (t.tm_hour, t.tm_min, t.tm_sec)
			v.send(SETTIME, timestr)
			print "done (%s)" % timestr
		elif opt == 'date':
			print v.recv(GETDATE)
		elif opt == 'setdate':
			t = time.localtime()
			datestr = "%s/%s/%s" % (t.tm_mday, t.tm_mon, t.tm_year % 100)
			v.send(SETDATE, datestr)
			print "done (%s)" % datestr

		elif opt == 'reset':
			v.send(RESET)
			print "done"

		elif opt == 'temp1': 	print v.recv(GETTEMP, 1)
		elif opt == 'temp2': 	print v.recv(GETTEMP, 2)
		elif opt == 'temp3': 	print v.recv(GETTEMP, 3)

		elif opt == 'bl_on': 	print v.recv(BACKLIGHT, 1)
		elif opt == 'bl_off':	print v.recv(BACKLIGHT, 0)
		elif opt == 'bl_fadeon':	print v.recv(BACKLIGHT, 3)
		elif opt == 'bl_fadeoff':	print v.recv(BACKLIGHT, 2)

		else: print 'no such command'
		exit(0)
			
if __name__ == "__main__" :
	try:
		main();
	except AssertionError,e:
		print 'Assertion: ' + e.message



