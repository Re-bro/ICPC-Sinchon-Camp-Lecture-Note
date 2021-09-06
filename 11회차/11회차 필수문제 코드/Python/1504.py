import sys
import heapq

r = sys.stdin.readline

def dijkstra(dis, S):
    pq = []
    dis[S] = 0
    heapq.heappush(pq, (0, S))
    while pq:
        d, u = heapq.heappop(pq)
        if d > dis[u]: continue
        for v, c in adj[u]:
            if dis[v] > d + c:
                dis[v] = d + c
                heapq.heappush(pq, (dis[v], v))


n, e = map(int, r().split())
adj = [[] for _ in range(n+1)]
for i in range(e):
    a, b, c = map(int, r().split())
    adj[a].append((b, c))
    adj[b].append((a, c))

dis1 = [10**18]*(n+1)
disv1 = [10**18]*(n+1)
disv2 = [10**18]*(n+1)
v1, v2 = map(int, r().split())
dijkstra(dis1, 1)
dijkstra(disv1, v1)
dijkstra(disv2, v2)

ans = min(dis1[v1] + disv1[v2] + disv2[n], dis1[v2] + disv2[v1] + disv1[n])
if ans  >= 10**18: print(-1)
else: print(ans)