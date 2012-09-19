import urllib

url = 'http://www.pythonchallenge.com/pc/def/'
imag = 'oxygen.png'

fin = urllib.urlopen(url+imag).read()
fout = open(imag, 'wb')
fout.write(fin)
fout.close()

import Image
im = Image.open(imag)
# y=43
# x=608

y = 43
collect = []
for x in range(0, 608, 7):
	collect.append(im.getpixel((x, y))[0])
"""
#following method would write 116 into 16
lx = im.size[0]
while (x+1 < lx):
	now = im.getpixel((x, y))
	if (now[0] != now[1]): break
	nxt = im.getpixel((x+1, y))
	if (now[:3] != nxt[:3]): collect.append(now[0])
	#print now, chr(now[0])
	x += 1
#collect.append(now[0])#
"""

print ''.join([chr(x) for x in collect])
# key = [105, 10, 16, 101, 103, 14, 105, 16, 121]
key = [105, 110, 116, 101, 103, 114, 105, 116, 121]
print ''.join([chr(x) for x in key])

#integrity
