import sys
import heapq

read = sys.stdin.readline

def dji(st) :
    global dist
    pq = []
    heapq.heappush(pq,[0,st]) # cost , st
    dist[st] = 0
    while pq :
        cost,here = heapq.heappop(pq)

        if dist[here] < cost : continue

        for nx,nc in adjs[here] :
            nxCost = cost + nc 
            if dist[nx] > nxCost : 
                dist[nx] = nxCost
                heapq.heappush(pq,[nxCost,nx])


V,E = map(int,read().split())
K = int(read())
adjs = [[] for _ in range(V+1)]
dist = [int(1e9) for _ in range(V+1)]
for _ in range(E) :
    x,y,c = map(int,read().split())
    adjs[x].append([y,c])

dji(K)

for i in range(1,V+1) :
    if dist[i] == int(1e9) :
        print("INF")
    else :
        print(dist[i])