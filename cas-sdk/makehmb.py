import sys
import os
import ntpath

print("Converting to HolzMod binary format")

inputFileName = str(sys.argv[1])
outputFileName = str(sys.argv[2])
appName = str(sys.argv[3])
appAuthor = str(sys.argv[4])
appVersion = str(sys.argv[5])
nameSize = 40 
authorSize = 40 
versionSize = 40 
headerSize = 0x80 
 
print("Input file: %s" % inputFileName)
print("Output file: %s" % outputFileName)
print("App name: %s" % appName)
print("App author: %s" % appAuthor)
print("App version: %s" % appVersion)

if len(appName) >= nameSize:
	print("App name is too long!")
	exit()
if len(appAuthor) >= authorSize:
	print("App author is too long!")
	exit()
if len(appVersion) >= versionSize:
	print("App version is too long!")
	exit()

with open(outputFileName, 'wb+') as outputFile:
	with open(inputFileName, 'rb') as inputFile:
		# first write everything full with 0
		for x in range(headerSize - 1):
			outputFile.seek(x)
			outputFile.write('\0'.encode())
				
		# now write the appName to the file
		tmp = 0
		for c in appName:
			outputFile.seek(tmp)
			outputFile.write(c.encode())
			tmp += 1
				
		# now write the appAuthor to the file
		tmp = nameSize
		for c in appAuthor:
			outputFile.seek(tmp)
			outputFile.write(c.encode())
			tmp += 1
				
		# now write the appName to the file
		tmp = authorSize + nameSize
		for c in appVersion:
			outputFile.seek(tmp)
			outputFile.write(c.encode())
			tmp += 1
		
		# now write the binary
		outputFile.seek(headerSize)
		outputFile.write(inputFile.read())

print("done")