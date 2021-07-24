import sys
from itertools import combinations

read = sys.stdin.readline

N,M = map(int,read().split())
board = [list(map(int,read().split())) for _ in range(N)]
H,C = [],[]
for i in range(N) :
    for j in range(N) :
        if board[i][j] == 1 :
            H.append([i,j])
        elif board[i][j] == 2 :
            C.append([i,j])

ans = int(1e9)
for case in combinations(C,M) :
    dist = 0
    for hx,hy in H :
        tmp = int(1e9)
        for cx,cy in case :
            tmp = min(tmp,abs(cx-hx)+abs(cy-hy))
        dist += tmp
    ans = min(ans,dist)
print(ans)