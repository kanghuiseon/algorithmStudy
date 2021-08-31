import sys

read = sys.stdin.readline
INF = int(1e9)

def bell(st) :
    global dist
    isCycle = False
    dist[st] = 0
    for i in range(1,N+1) :
        for j in range(M) :
            from_ = adjs[j][0]
            to_ = adjs[j][1]
            cost = adjs[j][2]

            if dist[from_] == INF : continue
            if dist[to_] > dist[from_] + cost :
                if i == N : isCycle = True
                dist[to_] = dist[from_] + cost
    return isCycle

N,M = map(int,read().split())
adjs = []
dist = [INF for _ in range(N+1)]
for _ in range(M) :
    x,y,c = map(int,read().split())
    adjs.append([x,y,c])

if bell(1) :
    print(-1)
else :
    for i in range(2,N+1) :
        print(dist[i] if dist[i] != INF else -1)
    