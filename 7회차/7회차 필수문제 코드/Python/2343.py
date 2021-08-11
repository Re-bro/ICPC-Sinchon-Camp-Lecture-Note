MM = 1000000000070708080700870
n, m = map(int, input().split())
A = [0] + list(map(int, input().split()))
s = 1
e = MM
ans = MM

def sol(mid):
    cnt = 1
    s = 0
    for i in range(1, n+1):
        if A[i] > mid: return 0
        if s + A[i] <= mid: s += A[i]
        else:
            cnt += 1
            s = A[i]
    if cnt <= m: return 1
    return 0

while s <= e:
    mid = (s+e)//2
    if sol(mid):
        e = mid-1
        ans = min(ans, mid)
    else: s = mid + 1

print(ans)