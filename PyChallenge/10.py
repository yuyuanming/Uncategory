# a = [1, 11, 21, 1211, 111221, 
# ? len(a[30])

import pdb

def gen(n):
    ret = ''
    cur = ''
    cnt = 0
    for ch in n:
        if ch == cur:
            cnt += 1
        else:
            if (cnt > 0):
                ret = ret + str(cnt) + str(cur)
            cur = ch
            cnt = 1
    return ret + str(cnt) + str(cur)

a = {0:'1'}
for i in xrange(1, 31):
    a[i] = gen(a[i-1])
    print 'len(a[%d]) = %d' % (i, len(a[i]))

#5808
