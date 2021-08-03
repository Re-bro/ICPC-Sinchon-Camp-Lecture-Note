import sys

r = sys.stdin.readline

n, m = map(int, r().split())

closed = [0]*(n+1)
dp = [[0]*(n+1) for _ in range(n+1)]

for i in list(map(int, r().split())):
    closed[i] = 1

for i in range(n+1):
    for j in range(n+1):
        dp[i][j] = 3923924394239

dp[0][0] = 0
for i in range(1, n+1):
    for j in range(n+1):
        if closed[i]: dp[i][j] = min(dp[i][j], dp[i-1][j])
        dp[i][j] = min(dp[i][j], dp[i-1][j] + 10000)
        if i >= 3 and j >= 1: dp[i][j] = min(dp[i][j], dp[i-3][j-1] + 25000)
        if i >= 5 and j >= 2: dp[i][j] = min(dp[i][j], dp[i-5][j-2] + 37000)
        if j + 3 <= n: dp[i][j] = min(dp[i][j], dp[i-1][j+3])

print(min(dp[n]))