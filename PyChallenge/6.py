import re

num = '90052'
nlist = []
while (1):
	try:
		nlist.append(num)
		text = open('./channel/'+num+'.txt').read()
		print text
		num = re.findall('[0-9]+', text)[0]
	except:
		break

import zipfile as zf
zif = zf.ZipFile('channel.zip')
ans = []
for it in nlist:
	#print it
	ch = zif.getinfo(it+'.txt').comment;
	#if ch != '*': ans.append(ch)
	ans.append(ch)

out = open('6.out', 'w')
out.write(''.join(ans))
out.close()

#hockey
#oxygen
