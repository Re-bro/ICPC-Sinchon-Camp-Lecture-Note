import sys

sys.setrecursionlimit(10**6)

ans1 = 0
ans2 = 0


def dfs(u, p, a, b):
    global ans1, ans2
    if u != r and len(adj[u]) == 1:
        if a == -1: ans2 = max(ans2, b)
        else: ans1 = a
        return
    if a >= 0:
        if len(adj[u]) > 2 or (len(adj[u]) >= 2 and u == r):
            ans1 = a
            for v, k in adj[u]:
                if v == p: continue
                dfs(v, u, -1, k)
        else:
            for v, k in adj[u]:
                if v == p: continue
                dfs(v, u, a+k, b)
    else:
        for v, k in adj[u]:
            if v == p: continue
            dfs(v, u, a, b + k)


n, r = map(int, input().split())
adj = [[] for _ in range(n+1)]
for i in range(1, n):
    a, b, d = map(int, input().split())
    adj[a].append((b, d))
    adj[b].append((a, d))
dfs(r, r, 0, 0)
print(ans1, ans2)

