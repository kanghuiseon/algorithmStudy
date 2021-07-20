import sys 

read = sys.stdin.readline
INF = int(1e9)

def floyd() :
    global adjs

    for k in range(1,N+1) :
        for i in range(1,N+1) :
            for j in range(1,N+1) :
                if i == j : continue
                if adjs[i][j] > adjs[i][k] + adjs[k][j] : 
                    adjs[i][j] = adjs[i][k] + adjs[k][j]

N = int(read())
M = int(read())
adjs = [[INF]*(N+1) for _ in range(N+1)]
for _ in range(M) :
    x,y,c = map(int,read().split())
    if adjs[x][y] > c :
        adjs[x][y] = c

floyd()

for i in range(1,N+1):
    for j in range(1,N+1) :
        print(adjs[i][j] if adjs[i][j] != INF else 0,end=' ')
    print()

