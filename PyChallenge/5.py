import urllib, pickle

fin = urllib.urlopen('http://www.pythonchallenge.com/pc/def/banner.p')
obj = pickle.load(fin)

out = open('5.out', 'w')
for line in obj:
	for ch, k in line: out.write(ch*k)
	out.write('\n')
out.close()

#channel
