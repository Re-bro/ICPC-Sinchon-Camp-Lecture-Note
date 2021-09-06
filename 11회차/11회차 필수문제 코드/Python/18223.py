import sys
import collections
import heapq


r = sys.stdin.readline
v, e, p = map(int, r().split())
adj = [[] for _ in range(v+1)]

dis1 = [10**9]*(v+1)
dis2 = [10**9]*(v+1)


def dijkstra(dis, S):
    dis[S] = 0
    pq = []
    heapq.heappush(pq, (0, S))
    while pq:
        d, u = heapq.heappop(pq)
        if d > dis[u]: continue
        for v, c in adj[u]:
            if dis[v] > d+c:
                dis[v] = d + c
                heapq.heappush(pq, (dis[v], v))

for i in range(e):
    a, b, c = map(int, r().split())
    adj[a].append((b, c))
    adj[b].append((a, c))

dijkstra(dis1, 1)
dijkstra(dis2, p)
if dis1[v] == dis1[p] + dis2[v]: print("SAVE HIM")
else: print("GOOD BYE")

