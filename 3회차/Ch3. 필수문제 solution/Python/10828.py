import sys

r = sys.stdin.readline

n = int(r())
st = []

for i in range(n):
    s = r().split()
    if s[0] == "push": st.append(s[1])
    elif s[0] == "pop":
        if st: print(st.pop())
        else: print(-1)

    elif s[0] == "size": print(len(st))

    elif s[0] == "empty":
        if st: print(0)
        else: print(1)

    else:
        if st: print(st[-1])
        else: print(-1)