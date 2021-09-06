import sys
import heapq

r = sys.stdin.readline

for _ in range(int(r())):
    K = int(r())
    check = [0]*(1010101)
    max_pq = []
    min_pq = []
    for i in range(K):
        a, b = r().split()
        b = int(b)
        if a == "D":
            if not max_pq: continue
            if b == 1:
                check[max_pq[0][1]] = 1
                heapq.heappop(max_pq)
            else:
                check[min_pq[0][1]] = 1
                heapq.heappop(min_pq)
        else:
            heapq.heappush(max_pq, (-b, i))
            heapq.heappush(min_pq, (b, i))
        while max_pq and check[max_pq[0][1]]: heapq.heappop(max_pq)
        while min_pq and check[min_pq[0][1]]: heapq.heappop(min_pq)

    if not max_pq: print("EMPTY")
    else: print(-max_pq[0][0], min_pq[0][0])
