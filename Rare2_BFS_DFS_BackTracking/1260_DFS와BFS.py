import sys
from collections import deque

read = sys.stdin.readline

def dfs(cur) :
    visited[cur] = 1
    print(cur,end=' ')
    for next in adjs[cur] :
        if visited[next] == 0 :
            dfs(next)

def bfs(cur) :
    q = deque()
    q.append(cur)

    while q :
        here = q.popleft()
        if visited[here] == 1 : continue
        print(here,end=' ')
        visited[here] = 1
        for next in adjs[here] :
            if visited[next] == 0 :
                q.append(next)

N,M,V = map(int,read().split())
adjs = [[] for _ in range(N+1)]
for _ in range(M) :
    x,y = map(int,read().split())
    adjs[x].append(y)
    adjs[y].append(x)

for i in range(1,N+1) :
    adjs[i].sort()

visited = [0 for _ in range(N+1)]
dfs(V)
print()
visited = [0 for _ in range(N+1)]
bfs(V)

