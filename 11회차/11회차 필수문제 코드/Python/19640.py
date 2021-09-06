import sys
import heapq
import collections

r = sys.stdin.readline

N, M, K = map(int,r().split())
L = [collections.deque() for _ in range(M)]

for i in range(N):
    a, b = map(int, r().split())
    c = i%M
    if i == K:
        L[c].append((-a, -b, c, 0))
    else:
        L[c].append((-a, -b, c))

ans = -1
que = []
for i in range(M):
    try: heapq.heappush(que, L[i].popleft())
    except: pass

while que:
    ans += 1
    a = heapq.heappop(que)
    if len(a) == 4:
        print(ans)
        exit()
    c = a[2]
    if L[c]:
        heapq.heappush(que,L[c].popleft())