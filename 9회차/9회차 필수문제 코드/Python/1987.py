import sys
import collections

r = sys.stdin.readline

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
ans = 0
visited = [0]*26
v = []

def dfs(x, y, cnt):
    global ans
    ans = max(ans, cnt)
    visited[ord(v[x][y])-ord("A")] = True
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < R and 0 <= ny < C and not visited[ord(v[nx][ny])-ord("A")]:
            dfs(nx, ny, cnt+1)
    visited[ord(v[x][y]) - ord("A")] = False

R, C = map(int, r().split())
for i in range(R): v.append(r().rstrip())
dfs(0, 0, 1)
print(ans)