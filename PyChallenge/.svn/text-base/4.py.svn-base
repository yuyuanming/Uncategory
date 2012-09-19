import urllib, re

base = 'http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing='
#num = '12345'
#num = '53522'
num = '46059'

while (1):
	try:
		text = urllib.urlopen(base+num).read()
		print text
		num = re.findall('[0-9]+', text)[0]
	except:
		break

#peak
