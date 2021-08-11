n, m, l = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
a.append(l)
a = [0] + a

s = 1
e = 1000
ans = 10000

def sol(mid):
    cnt = 0
    for i in range(1, n+2):
        cnt += (a[i] - a[i-1] -1)//mid
    if cnt <= m: return 1
    return 0

while s <= e:
    mid = (s+e)//2
    if sol(mid):
        e = mid -1
        ans = min(ans, mid)
    else: s = mid + 1
print(ans)