#!/usr/bin/env python2
#-*- coding: utf8 -*-


import os, sys
import time, getopt
from avr import * 
from vusb import * 

GETTIME, SETTIME, GETTEMP = range(3)

def send(v, action, value, param = 0):
	while True:
		try: 
			v.send(action, value, param)
			break
		except Exception, e: pass


def recv(v, action, param = 0):
	while True:
		try: 
			return v.recv(action, param)
		except Exception, e: pass




def main():
	try:
		opts, args = getopt.getopt(sys.argv[1:], 'sgt:');
		if len(opts) < 1: 
			raise getopt.GetoptError("asd")

	except getopt.GetoptError, err:
		print "bad args: -sg -t[0-3]"
		exit()

	v = Vusb();

	for o, a in opts:
		if o == '-g':
			print recv(v, GETTIME)
		if o == '-s':
			send(v, SETTIME, "9/43/00")
		if o == '-t':
			if not int(a) in range(1,4):
				assert False, "bad option param"

			print recv(v, GETTEMP, a)
			

if __name__ == "__main__" :
	try:
		main();
	except AssertionError,e:
		print 'Assertion: ' + e.message



