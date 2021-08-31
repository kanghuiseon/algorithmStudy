import sys

read = sys.stdin.readline

def floyd() :
    for k in range(1,N+1) :
        for i in range(1,N+1) :
            for j in range(1,N+1) :
                if adjs[i][k] == 1 and adjs[k][j] == 1 :
                    adjs[i][j] = 1

N,M = map(int,read().split())
adjs = [[0] * (N+1) for _ in range(N+1)]
for _ in range(M) :
    x,y = map(int,read().split())
    adjs[x][y] = 1

floyd()
ans = 0
for i in range(1,N+1) :
    cnt = 0
    for j in range(1,N+1) :
        cnt += (adjs[i][j] + adjs[j][i])
    if cnt == N-1 :
        ans += 1
print(ans)