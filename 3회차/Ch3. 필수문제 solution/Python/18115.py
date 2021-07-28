import sys
import collections

r = sys.stdin.readline

N = int(r())
L = list(map(int, r().split()))
B = collections.deque()
for i in range(1, N+1):
    cmd = L[N-i]
    if cmd == 1:
        B.appendleft(i)
    elif cmd == 2:
        b = B.popleft()
        B.appendleft(i)
        B.appendleft(b)
    else:
        B.append(i)

for i in B:
    print(i)