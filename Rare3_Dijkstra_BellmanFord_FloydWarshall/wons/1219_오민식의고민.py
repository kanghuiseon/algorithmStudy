import sys

read = sys.stdin.readline
INF = int(1e9)

def bell() :
    dist[S] = pay[S]
    isCycle = False
    for i in range(N) :
        for j in range(M) :
            from_ = adjs[j][0]
            to_ = adjs[j][1]
            cost = adjs[j][2]

            if dist[from_] == -INF : continue
            if dist[to_] < dist[from_] - cost + pay[to_] :
                if i == N-1 : 
                    if to_ == D or from_ == D:
                        isCycle = True
                dist[to_] = dist[from_] - cost + pay[to_]

    return isCycle

N,S,D,M = map(int,read().split())
adjs = []
dist = [-INF for _ in range(N)]

for _ in range(M) :
    x,y,c = map(int,read().split())
    adjs.append([x,y,c])
pay = list(map(int,read().split()))

isCycle = bell()

if dist[D] == -INF :
    print("gg")
elif isCycle : 
    print("Gee")
else :
    print(dist[D])
