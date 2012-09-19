import re, urllib

text = urllib.urlopen("http://www.pythonchallenge.com/pc/def/integrity.html")

for line in text:
	if line[:2] == 'un': un = line[5:-2]
	if line[:2] == 'pw': pw = line[5:-2]

import bz2
print un.decode('string_escape').decode('bz2')
print pw.decode('string_escape').decode('bz2')

#huge
#file
