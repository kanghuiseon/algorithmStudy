import sys

read = sys.stdin.readline
INF = int(1e9)

T = int(read())

def bell() :
    isCycle = False
    for i in range(1,N+1) :
        if dist[i] == INF : 
            dist[i] = 0
        for j in range(2*M+W) :
            from_ = adjs[j][0]
            to_ = adjs[j][1]
            cost = adjs[j][2]

            if dist[from_] == INF : continue
            if dist[to_] > dist[from_] + cost : 
                if i == N : 
                    isCycle = True
                    break
                dist[to_] = dist[from_] + cost
    return isCycle

for _ in range(T) :
    N,M,W = map(int,read().split())

    adjs = []
    dist = [INF for _ in range(N+1)]
 
    for _ in range(M) :
        S,E,T = map(int,read().split())
        adjs.append([S,E,T])
        adjs.append([E,S,T])
    for _ in range(W) :
        S,E,T = map(int,read().split())
        adjs.append([S,E,-T])
    
    if bell() :
        print("YES")
    else :
        print("NO")