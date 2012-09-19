import urllib, re, string
text = urllib.urlopen("http://www.pythonchallenge.com/pc/def/ocr.html").read()

text = re.findall("<!--([^-]*)-->", text, re.S)[1]
print ''.join([ch for ch in text if ch in string.ascii_lowercase])

#equality
