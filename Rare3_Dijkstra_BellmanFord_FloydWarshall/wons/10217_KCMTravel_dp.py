import sys


read = sys.stdin.readline
INF = int(1e9)

T = int(read())
for _ in range(T) :
    N,M,K = map(int,read().split())
    adjs = [[] for _ in range(N+1)]
    for _ in range(K) :
        x,y,c,d = map(int,read().split())
        adjs[x].append([y,c,d])
    
    dp = [[INF] * (M+1) for _ in range(N+1)]
    dp[1][0] = 0 # vertex, budget, dist 

    for budget in range(M+1) :
        for cur in range(1,N+1) :
            if dp[cur][budget] == INF : continue

            dist = dp[cur][budget]
            for nx,nc,nd in adjs[cur] :
                nxBudget = budget + nc
                nxDist = dist + nd
                if nxBudget > M : continue
                dp[nx][nxBudget] = min(dp[nx][nxBudget],nxDist)
    
    ans = min(dp[N])
    if ans == INF :
        print("Poor KCM")
    else :
        print(ans)