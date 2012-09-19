import urllib, re, string
text = urllib.urlopen("http://www.pythonchallenge.com/pc/def/equality.html").read()

text = re.findall("<!--([^-]*)-->", text, re.S)[0]
print ''.join(re.findall('[^A-Z][A-Z]{3}([a-z])[A-Z]{3}[^A-Z]', text, re.S))

#linkedlist
