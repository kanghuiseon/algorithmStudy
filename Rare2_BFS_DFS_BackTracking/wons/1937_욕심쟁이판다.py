
import sys
read = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

def dfs(x,y) :
    if dp[x][y] : return dp[x][y]
    dp[x][y] = 1
    
    for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
        nx,ny = x+dx, y+dy

        if 0 <= nx < N and 0 <= ny < N and board[nx][ny] > board[x][y]:
            dp[x][y] = max(dp[x][y],dfs(nx,ny)+1)

    return dp[x][y]

N = int(read())
board = [list(map(int,read().split())) for _ in range(N)]
dp = [[0] * N for _ in range(N)]
ans = 0 
for i in range(N) : 
    for j in range(N) :
        ans = max(ans,dfs(i,j))

print(ans)