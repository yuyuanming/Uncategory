import urllib, re

#=====================getting the coordinates======================

base = 'http://www.pythonchallenge.com/pc/return/good.html'
msg = urllib.urlopen(base).read()
first, second = re.findall('(?:first|second):([^:]*)\n\n', msg)

def handle(s):
    return map(int, s.replace('\n', '').split(','))

first = handle(first)
second = handle(second)

#=====================Drawing the picture===========================

import Image, ImageDraw
im = Image.new('1', (500, 500))
draw = ImageDraw.Draw(im)
draw.line(first, fill=128)
draw.line(second, fill=128)

im.save('9.png')
del draw

#bull
