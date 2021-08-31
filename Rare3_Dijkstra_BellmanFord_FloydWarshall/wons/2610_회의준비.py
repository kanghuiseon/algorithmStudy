import sys

read = sys.stdin.readline
INF = int(1e9)

def find(x) :
    if par[x] == x : return par[x]
    else :
        par[x] = find(par[x])
        return par[x]
def merge(x,y) :
    p_x = find(x)
    p_y = find(y)
    if p_x == p_y : return
    par[p_x] = p_y

def floyd() :
    for k in range(1,N+1) : 
        for i in range(1,N+1) :
            for j in range(1,N+1) :
                if i == j : dist[i][j] = 0
                if dist[i][j] > dist[i][k] + dist[k][j] :
                    dist[i][j] = dist[i][k] + dist[k][j]

N = int(read()); M = int(read())
par = [i for i in range(N+1)]
dist = [[INF] * (N+1) for _ in range(N+1)]

for _ in range(M) :
    x,y = map(int,read().split())
    dist[x][y] = dist[y][x] = 1
    merge(x,y)

floyd()

ans = [[INF,0] for _ in range(N+1)]
for i in range(1,N+1) :
    p_i,tmp = find(i),0
    for j in range(1,N+1) :
        if dist[i][j] == INF : continue
        tmp = max(tmp,dist[i][j])

    if ans[p_i][0] > tmp : 
        ans[p_i][0] = tmp
        ans[p_i][1] = i

president = []
for i in range(1,N+1) :
    if ans[i][1] == 0 : continue
    president.append(ans[i][1])

president.sort()
print(len(president))
for p in president :
    print(p)



