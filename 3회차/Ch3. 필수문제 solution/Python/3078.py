import sys
import collections

r = sys.stdin.readline

cnt = [0]*21

n, k = map(int, r().split())
q = collections.deque()
ans = 0
for i in range(n):
    s = r().rstrip()
    if len(q) > k: cnt[q.popleft()] -= 1;
    ans += cnt[len(s)]
    cnt[len(s)] += 1
    q.append(len(s))
print(ans)