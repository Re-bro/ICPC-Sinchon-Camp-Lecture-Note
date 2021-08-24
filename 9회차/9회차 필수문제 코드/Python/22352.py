import sys
import collections

r = sys.stdin.readline

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

N, M = map(int, r().split())
AL = []
BL = []
for i in range(N):
    AL.append(list(map(int, r().split())))

for i in range(N):
    BL.append(list(map(int, r().split())))

visit = [[0]*(M+1) for _ in range(N+1)]

flag = 1
for i in range(N):
    for j in range(M):
        if AL[i][j] != BL[i][j]:
            que = collections.deque()
            flag = 0
            que.append([i, j])
            visit[i][j] = 1
            while que:
                x, y = que.popleft()
                for d in range(4):
                    ry = y + dy[d]
                    rx = x + dx[d]
                    if 0 <= rx < N and 0 <= ry < M and visit[rx][ry] == 0 and AL[rx][ry] == AL[i][j]:
                        visit[rx][ry] = 1
                        AL[rx][ry] = BL[i][j]
                        que.append([rx, ry])
            AL[i][j] = BL[i][j]


        if flag == 0: break
    if flag == 0: break


if AL == BL:
    print("YES")
else:
    print("NO")