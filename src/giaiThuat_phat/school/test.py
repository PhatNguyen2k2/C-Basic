x1, y1, x2, y2 = map(int, input().split())
a1, b1, a2, b2 = map(int, input().split())

dt1 = (x2 - x1) * (y2 - y1)
dt2 = (a2 - a1) * (b2 - b1)

l1 = max(x1, a1)
k1 = max(y1, b1)
l2 = min(x2, a2)
k2 = min(y2, b2)
tdt = max(0, l2 - l1) * max(0, k2 - k1)

dtcp = dt1 + dt2 - tdt

if l2 <= l1 or k2 <= k1:
    loop = False
else:
    loop = True

if loop:
    print(1)
else:
    print(0)
print(dtcp)