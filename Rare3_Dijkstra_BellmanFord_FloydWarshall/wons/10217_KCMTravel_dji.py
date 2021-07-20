import sys
import heapq

read = sys.stdin.readline
INF = int(1e9)

def dji() :
    pq = []
    dist = [[INF] * (M+1) for _ in range(N+1)]
    heapq.heappush(pq,[0,0,1])  # dist , budget, cur   
    dist[1][0] = 0

    while pq :
        curDist, curBud, cur = heapq.heappop(pq)

        if dist[cur][curBud] < curDist : continue

        for nx,nc,nd in adjs[cur] :
            nxBud = nc + curBud
            nxDist = nd + curDist
            if curBud + nc > M : continue
            if dist[nx][nxBud] > nxDist :
                for m in range(nxBud,M+1) :
                    if dist[nx][m] > nxDist :
                        dist[nx][m] = nxDist
                heapq.heappush(pq,[nxDist,nxBud,nx])

    return dist[N][M]

T = int(read())
for _ in range(T) :
    N,M,K = map(int,read().split())
    adjs = [[] for _ in range(N+1)]
    for _ in range(K) :
        x,y,c,d = map(int,read().split())
        adjs[x].append([y,c,d])
    
    ans = dji()
    if ans == INF :
        print("Poor KCM")
    else :
        print(ans)