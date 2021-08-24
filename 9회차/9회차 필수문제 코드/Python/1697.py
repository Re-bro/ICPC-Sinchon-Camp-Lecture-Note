import sys
import collections

r = sys.stdin.readline

adj = [[] for _ in range(101010)]

n, k = map(int, r().split())
for i in range(100001):
    if i > 0: adj[i].append(i-1)
    if i < 100000: adj[i].append(i+1)
    if i*2 <= 100000: adj[i].append(i*2)

que = collections.deque()

que.append(n)
dis = [-1]*101010
dis[n] = 0
while que:
    u = que.popleft()
    for v in adj[u]:
        if dis[v] == -1:
            dis[v] = dis[u] + 1
            que.append(v)
print(dis[k])