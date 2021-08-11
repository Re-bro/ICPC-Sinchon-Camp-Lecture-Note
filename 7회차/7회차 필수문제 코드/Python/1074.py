n, r, c = map(int, input().split())

def sol(x, y, size):
    if size == 1: return 0
    ret = 0
    s = size//2
    if x + s > r and y + s > c:
        ret += sol(x, y, s)
        return ret
    ret += s*s
    if x + s > r and y + s <= c:
        ret += sol(x, y + s, s)
        return ret
    ret += s * s
    if x + s <= r and y + s > c:
        ret += sol(x+s, y, s)
        return ret
    ret += s*s
    ret += sol(x+s, y+s, s)
    return ret


size = 1
for i in range(n): size *= 2
print(sol(0, 0, size))