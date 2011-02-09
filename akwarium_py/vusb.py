#-*- coding: utf8 -*-

import usb, time


class Vusb:
	USB_VENDOR_ID = 0x16C0
	USB_PRODUCT_ID = 0x03e8

	REQUEST_TYPE = usb.TYPE_VENDOR | usb.RECIP_DEVICE  
	USB_BUFFER_SIZE = 2
	CMD_ZERO = 0

	def __init__(self):
		device = self.findDevice(self.USB_VENDOR_ID, self.USB_PRODUCT_ID)
		if not device:
			raise Exception('Device not available')
		self.handle = device.open()

	def findDevice(self, vendor_id, product_id):
		buses = usb.busses()
		for bus in buses :
			for device in bus.devices :
				if device.idVendor == vendor_id and device.idProduct == product_id:
					return device
		return None

	def getBufferSize(self):
		return self.send_cmd(self.CMD_ZERO)

	def send(self, action, value = 'reset'):
		c = 0
		while True:
			c += 1
			try: 
				self._send(action, value)
				break
			except Exception, e: 
				print e
				time.sleep(0.3)
				pass
		print "count: %s" % c


	def recv(self, action, param = 0):
		c = 0
		while True:
			c += 1
			try: 
				res = self._recv(action, param)
				print "count: %s" % c
				return res
			except Exception, e: 
				print e
				time.sleep(0.3)
				pass

	### PRIVATE ###

	def _send(self, cmd, buffer):
		val = ''
		val = self.handle.controlMsg(
				requestType = self.REQUEST_TYPE | usb.ENDPOINT_OUT, 
				request = cmd, 
				value = len(buffer), 
				buffer = buffer, # self.USB_BUFFER_SIZE
				timeout = 400
				)
		return val

	def _recv(self, cmd, param):
		buffer = ''
		res = self.handle.controlMsg(
			requestType = self.REQUEST_TYPE | usb.ENDPOINT_IN, 
			request = cmd, 
			value = int(param), 
			buffer = 1000, #"   fds f  1000", # self.USB_BUFFER_SIZE
			timeout = 400
			)
		for c in res: buffer += chr(c)
		return buffer



