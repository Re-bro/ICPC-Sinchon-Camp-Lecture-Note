import sys

input = sys.stdin.readline


def sol(mid):
    cnt = 0
    for i in range(1, n+1):
        cnt += L[i]//mid
        if cnt >= m: return 1
    return 0


n, k, m = map(int, input().split())
L = [0]*1010101
for i in range(1, n+1):
    L[i] = int(input())
    if L[i] >= 2*k: L[i] -= 2*k
    else: L[i] = max(0, L[i]-k)
s = 1
e = 1000000000
ans = -1

while s <= e:
    mid = (s+e)//2
    if sol(mid):
        ans = max(ans, mid)
        s = mid + 1
    else: e = mid-1
print(ans)