import sys

r = sys.stdin.readline

N = int(r())
a = []
s = []
for _ in range(N):
    a.append(list(map(int, r().split())))

a.sort()

for i in range(N):
    while len(s) >= 2:

        l = s[-1][0]
        h = s[-1][1]
        s.pop()
        if s[-1][1] >= h and a[i][1] >= h: continue
        s.append([l, h])
        break
    s.append(a[i])

ans = 0
prev_l = s[-1][0]
prev_h = s[-1][1]
ans += prev_h
s.pop()

while s:
    l = s[-1][0]
    h = s[-1][1]
    ans += min(prev_h, h) * (prev_l - (l+1))
    ans += h
    prev_h = h
    prev_l = l
    s.pop()
print(ans)