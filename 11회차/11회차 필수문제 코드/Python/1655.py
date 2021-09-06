import sys
import heapq

r = sys.stdin.readline

N = int(r())
S = []
L = []

for _ in range(N):
    K = int(r())
    if not S or -S[0] >= K: heapq.heappush(S, -K)
    else: heapq.heappush(L, K)
    while len(S) < len(L):
        heapq.heappush(S, -L[0])
        heapq.heappop(L)
    while len(S) > len(L)+1:
        heapq.heappush(L, -S[0])
        heapq.heappop(S)
    print(-S[0])