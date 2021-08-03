import sys

r = sys.stdin.readline


n, m = map(int, r().split())
A = [[0]*(m+1) for _ in range(n+1)]
dp = [[0]*(m+1) for _ in range(n+1)]

for i in range(1, n+1):
    L = list(map(int, r().split()))
    for j in range(1, m+1):
        A[i][j] = L[j-1]

for i in range(1, n+1):
    for j in range(1, m+1):
        dp[i][j] = max(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + A[i][j]
print(dp[n][m])
