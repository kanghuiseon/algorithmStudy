import sys

read = sys.stdin.readline

seq = read().strip()
bomb = read().strip()
bombL = len(bomb)
st = []

for s in seq :
    st.append(s)

    if bomb[-1] == s and "".join(st[-bombL:]) == bomb :
        del st[-bombL:]
ans = "".join(st)
if ans == "" :
    print("FRULA")
else :
    print(ans)