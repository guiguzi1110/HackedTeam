#! /usr/bin/env python

#Copyright HT srl, 2009-2010
#http://www.hackingteam.it/ for more information

#cod

# RLEncode
# canvas

import os
import sys

class RLEncode():
	
	def encode(self, input_string):
		count = 1
		prev = ''
		lst = []
		for character in input_string:
			if character != prev:
				if prev:
					entry = (prev,count)
					lst.append(entry)
					#print lst
				count = 1
				prev = character
			elif character == prev:
				count += 1
		else:
			entry = (character,count)
			lst.append(entry)
		
		#transform to a PS RLE string
		out=""
		lastones=""
		for entry in lst:
			if entry[1] == 1:
				if len(lastones) < 128:
					lastones += entry[0]
				else:
					out += chr(len(lastones)-1) + lastones
					lastones = entry[0]
			else:
				if len(lastones):
					out += chr(len(lastones)-1) + lastones
					lastones = ""
				c=entry[1]
				while c > 0:
					if c > 128:
						out += chr(257 - 128) + entry[0]
						c -= 128
					elif c > 1:
						out += chr(257 - c) + entry[0]
						c = 0
					else:
						lastones += entry[0]
						c = 0
		if len(lastones):
			out += chr(len(lastones)-1) + lastones
		out += chr(0x80)
		
		return out

if __name__=='__main__':
	if len(sys.argv) != 3:
		print "[ERROR] %s require 2 parameters"%(DESCRIPTION)
		sys.exit(0)

	if os.path.isfile(sys.argv[1]) == False:
		print "[ERROR] File %s doesn't exists."%(sys.argv[1])
		sys.exit(0)

	if os.path.getsize(sys.argv[1]) == 0:
		print "[ERROR] File %s has length zero."%(sys.argv[1])
		sys.exit(0)

	print 'Encoding with rle'
	
	encoding = RLEncode()
	
	fd = file(sys.argv[1], 'rb')
	data = fd.read()
	fd.close()
	
	data = encoding.encode(data)
	
	fd = file(sys.argv[2], 'wb')
	fd.write(data)
	fd.close()
	
	print 'done'