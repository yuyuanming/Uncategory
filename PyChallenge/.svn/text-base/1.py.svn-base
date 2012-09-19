import string

def decode(text):
	out = ''
	for ch in text:
		if ch in tab: out += tab[ord(ch) - ord('a')]
		else: out += ch
	return out

text = raw_input('Please enter the encrypted code:\n\n')
tab = string.ascii_lowercase[2:] + 'ab'

print decode(text)
print
print decode('map')

#ocr
