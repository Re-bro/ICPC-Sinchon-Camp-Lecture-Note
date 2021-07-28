import sys
from collections import deque

r = sys.stdin.readline

n, m = map(int, r().split())
D, S, dq1, dq2 = deque(), deque(), deque(), deque()

for i in range(n):
    a, b = map(int, r().split())
    D.appendleft(a)
    S.appendleft(b)

turn = 1
k1, k2 = 0, 0

for i in range(m):
    if turn:
        k1 = D.popleft()
        dq1.append(k1)
    else:
        k2 = S.popleft()
        dq2.append(k2)

    if not D:
        print("su")
        exit()

    if not S:
        print("do")
        exit()

    if k1 == 5 or k2 == 5:
        while dq2: D.append(dq2.popleft())
        while dq1: D.append(dq1.popleft())
        k1 = k2 = 0

    elif k1 + k2 == 5 and k1 != 0 and k2 != 0:
        while dq1: S.append(dq1.popleft())
        while dq2: S.append(dq2.popleft())
        k1 = k2 = 0
    turn = 1 ^ turn
if len(D) < len(S): print("su")
elif len(D) > len(S): print("do")
else: print("dosu")