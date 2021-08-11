
def dnc(l, r):
    if l == r: return A[l]
    if l > r : return 0
    mid = (l+r)//2
    res = max(dnc(l, mid-1), dnc(mid+1, r))
    height = A[mid]
    res = max(res, A[mid])
    s = mid
    e = mid
    while s > l or e < r:
        if (s == l or (A[e+1] >= A[s-1])) and e < r:
            e += 1
            height = min(height, A[e])
        else:
            s -= 1
            height = min(height, A[s])
        res = max(res, height*(e-s+1))
    return res


n = int(input())
A = [0]
for i in range(n):
    A.append(int(input()))
A.append(0)

print(dnc(1, n))