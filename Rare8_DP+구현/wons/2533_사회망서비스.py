import sys 
sys.setrecursionlimit(int(1e9))
read = sys.stdin.readline

def dfs(cur) :
    visited[cur] = 1

    dp[cur][0] = 0
    dp[cur][1] = 1

    for nx in adjs[cur] :
        if visited[nx] != 0 : continue

        dfs(nx)

        dp[cur][0] += dp[nx][1]
        dp[cur][1] += min(dp[nx][0],dp[nx][1])

    

N = int(read())
adjs = [[] for _ in range(N+1)]
visited = [0 for _ in range(N+1)]
dp = [[0]*2 for _ in range(N+1)]
for _ in range(N-1) :
    x,y = map(int,read().split())
    adjs[x].append(y)
    adjs[y].append(x)

dfs(1)

print(min(dp[1]))