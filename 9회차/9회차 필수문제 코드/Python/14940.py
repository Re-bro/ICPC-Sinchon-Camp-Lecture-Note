import sys
import collections

r = sys.stdin.readline

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

n, m = map(int, r().split())
sx, sy = 0, 0
A = []
for i in range(n):
    A.append(list(map(int, r().split())))
for i in range(n):
    for j in range(m):
        if A[i][j] == 2:
            sx, sy = i, j

dis = [[-1]*(m+1) for _ in range(n+1)]
que = collections.deque()
que.append((sx, sy))
dis[sx][sy] = 0

while que:
    x, y = que.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if A[nx][ny] == 1 and dis[nx][ny] == -1:
                dis[nx][ny] = dis[x][y]+1
                que.append((nx, ny))
for i in range(n):
    for j in range(m):
        if A[i][j]: print(dis[i][j], end=" ")
        else: print(0, end=" ")
    print()