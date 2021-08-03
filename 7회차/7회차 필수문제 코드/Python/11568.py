import sys

r = sys.stdin.readline

n = int(r())
A = [0] + list(map(int, r().split()))
dp = [0]*(n+1)

for i in range(n+1):
    dp[i] = 1
    for j in range(1, i):
        if A[j] < A[i]: dp[i] = max(dp[i], dp[j] +1)

print(max(dp))