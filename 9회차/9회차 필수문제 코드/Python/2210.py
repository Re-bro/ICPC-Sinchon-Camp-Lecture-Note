import sys
import collections

r = sys.stdin.readline

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

A = []
chk = [0]*(1000000)

def dfs(x, y, k, cnt):
    if cnt == 6:
        chk[k] = True
        return
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < 5 and 0 <= ny < 5:
            dfs(nx, ny, k*10+ A[nx][ny], cnt+1)

for i in range(5): A.append(list(map(int, r().split())))

for i in range(5):
    for j in range(5):
        dfs(i, j, A[i][j], 1)
ans = 0
for i in range(1000000):
    if chk[i]: ans += 1
print(ans)