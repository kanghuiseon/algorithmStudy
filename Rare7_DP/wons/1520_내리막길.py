import sys 
sys.setrecursionlimit(int(1e9))
read = sys.stdin.readline

def dfs(x,y) :
    if x == N-1 and y == M-1 : return 1
    if dp[x][y] != -1 : return dp[x][y]

    dp[x][y] = 0
    for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
        nx = x + dx
        ny = y + dy

        if 0 <= nx < N and 0 <= ny < M and board[x][y] > board[nx][ny] :
            dp[x][y] += dfs(nx,ny)

    return dp[x][y]

N,M = map(int,read().split())
board = [list(map(int,read().split())) for _ in range(N)]
dp = [[-1]*(M+1) for _ in range(N+1)]
print(dfs(0,0))

for row in dp :
    print(*row)