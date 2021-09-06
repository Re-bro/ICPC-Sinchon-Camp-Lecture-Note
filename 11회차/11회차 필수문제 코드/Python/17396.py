import sys
import heapq

r = sys.stdin.readline

N, M = map(int, r().split())
a = list(map(int, r().split()))
adj = [[] for _ in range(N+1)]



for i in range(M):
    u, v, c = map(int, r().split())
    if (a[u] == 0 and a[v] == 0) or u == N-1 or v == N-1:
        adj[u].append((v, c))
        adj[v].append((u, c))
dis = [10**18]*(N+1)

pq = []
heapq.heappush(pq, (0, 0))
dis[0] = 0

while pq:
    d, u = heapq.heappop(pq)
    if d > dis[u]: continue
    for v, c in adj[u]:
        if dis[v] > d + c:
            dis[v] = d + c
            if (v != N-1): heapq.heappush(pq, (dis[v], v))

if dis[N-1] == 10**18: print(-1)
else: print(dis[N-1])