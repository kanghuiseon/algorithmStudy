import sys
from collections import Counter
read = sys.stdin.readline

N = int(read())
cat = read().strip()

L,R = 0,0
cnt,ans = 1,0

while L <= R < len(cat)-1 :
    if cat[R] == cat[R+1] or cat[L] == cat[R+1] :
        R += 1
    else :
        R += 1
        while len(Counter(cat[L:R+1]).keys()) > N :
            L += 1
    ans = max(ans,R-L+1)
print(ans)
