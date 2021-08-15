import sys
from collections import deque

read = sys.stdin.readline

def bfs(ed) :
    q = deque()
    dp = [0 for _ in range(N+1)]
    for i in range(1,N+1) :
        if before[i] == 0 :
            q.append(i)
            dp[i] = cost[i-1]
    while q :
        cur = q.popleft()
        
        for nx in adjs[cur] :
            dp[nx] = max(dp[nx],dp[cur]+cost[nx-1])
            before[nx] -= 1

            if before[nx] == 0 :
                q.append(nx)

    return dp[ed]

T = int(read())
for _ in range(T) :
    N,K = map(int,read().split())
    cost = list(map(int,read().split()))
    adjs = [[] for _ in range(N+1)]
    before = [0 for _ in range(N+1)]

    for _ in range(K) :
        x,y = map(int,read().split())
        adjs[x].append(y)
        before[y] += 1
    W = int(read())
    print(bfs(W))



