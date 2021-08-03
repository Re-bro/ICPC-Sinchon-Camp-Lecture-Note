import sys

r = sys.stdin.readline

n, m = map(int, r().split())

A = [[0]*(101) for _ in range(101)]
psum = [[0]*(101) for _ in range(101)]

for i in range(1, n+1):
    s = r().rstrip()
    for j in range(1, m+1):
        A[i][j] = ord(s[j-1]) - ord('0')

    for i in range(1, n+1):
        for j in range(1, m+1):
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + A[i][j]

    ans = 0
    for i in range(1, m-1):
        k1 = psum[n][i]
        for j in range(i+1, m):
            k2 = psum[n][j] - k1
            k3 = psum[n][m] - psum[n][j]
            ans = max(ans, k1*k2*k3)



    for i in range(1, n-1):
        k1 = psum[i][m]
        for j in range(i+1, n):
            k2 = psum[j][m] - k1
            k3 = psum[n][m] - psum[j][m]
            ans = max(ans, k1*k2*k3)

    for i in range(1, m):
        k1 = psum[n][i]
        for j in range(1, n):
            k2 = psum[j][m] - psum[j][i]
            k3 = psum[n][m] - k1 - k2
            ans = max(ans, k1*k2*k3)

    for i in range(1, n):
        k1 = psum[i][m]
        for j in range(1, m):
            k2 = psum[n][j] - psum[i][j]
            k3 = psum[n][m] - k1 - k2
            ans = max(ans, k1*k2*k3)

    for i in range(1, m):
        k1 = psum[n][m] - psum[n][i]
        for j in range(1, n):
            k2 = psum[j][i]
            k3 = psum[n][i] - k2
            ans = max(ans, k1*k2*k3)

    for i in range(1, n):
        k1 = psum[n][m] - psum[i][m]
        for j in range(1, m):
            k2 = psum[i][j]
            k3 = psum[i][m] - k2
            ans = max(ans, k1 * k2 * k3)
print(ans)