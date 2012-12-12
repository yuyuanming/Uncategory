import Image, math

def get_pixel(t):
    t = (100 * 100 - 1) - t
    shell = int((math.sqrt(t) + 1) / 2)
    leg = 0 if (shell == 0) else int((t - (2 * shell - 1) ** 2) / 2 / shell)
    elt = t - (2 * shell - 1) ** 2 - 2 * shell * leg - shell + 1
    
    if leg == 0:
        x, y = shell, elt
    elif leg == 1:
        x, y = -elt, shell
    elif leg == 2:
        x, y = -shell, -elt
    else:
        x, y = elt, -shell

    return (49 + x, 50 - y)

# Download the image from: http://www.pythonchallenge.com/pc/return/wire.png

input = Image.open("wire.png")
output = Image.new("RGB", (100, 100))

for i, px in enumerate(input.getdata()):
    output.putpixel(get_pixel(i), px)

output.save("new.jpg")

