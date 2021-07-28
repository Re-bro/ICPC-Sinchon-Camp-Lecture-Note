import sys

r = sys.stdin.readline

s = r().rstrip()
st = []

for i in range(len(s)):
    if s[i] == "(": st.append(-1)
    elif s[i] == "[": st.append(-2)
    else:
        if not st or (st[-1] > 0 and len(st) == 1):
            print(0)
            exit()
        now = 1

        if st[-1] > 0: now = st.pop()
        if s[i] == ")" and st[-1] == -1:
            st.pop()
            st.append(now*2)

        elif s[i] == "]" and st[-1] == -2:
            st.pop()
            st.append(now*3)
        else:
            print(0)
            exit()

        if len(st) >= 2:
            tmp = st.pop()
            if st[-1] > 0 and tmp > 0:
                tmp += st.pop()

            st.append(tmp)

if len(st) == 1 and st[-1] > 0: print(st[-1])
else: print(0)