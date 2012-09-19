import Image

im = Image.open('11.jpg')
w = im.size[0]
h = im.size[1]

odd = even = Image.new(im.mode, (w/2, h/2))

for x in range(w):
    for y in range(h):
        p = im.getpixel((x, y))
        if (x%2 == y%2):
            odd.putpixel((x/2, y/2), p)
        else:
            even.putpixel((x/2, y/2), p)

odd.show()
even.show()

#evil
