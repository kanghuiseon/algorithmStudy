import sys

read = sys.stdin.readline

N,M = map(int,read().split())
board = [list(map(int,read().split())) for _ in range(N)]
dpup = [[0]*(M+1) for _ in range(N+1)]
dpdown = [[0]*(M+1) for _ in range(N+1)]

dpup[N-1][0] = board[N-1][0]
for i in range(N-1,-1,-1) :
    for j in range(M) :
        if i == N-1 : dpup[i][j] = dpup[i][j-1] + board[i][j]
        elif j == 0 : dpup[i][j] = dpup[i+1][j] + board[i][j]
        else : dpup[i][j] = max(dpup[i+1][j],dpup[i][j-1]) + board[i][j]

dpdown[N-1][M-1] = board[N-1][M-1]
for i in range(N-1,-1,-1) :
    for j in range(M-1,-1,-1) :
        if i == N-1 : dpdown[i][j] = dpdown[i][j+1] + board[i][j]
        elif j == M-1 : dpdown[i][j] = dpdown[i+1][j] + board[i][j]
        else : dpdown[i][j] = max(dpdown[i+1][j],dpdown[i][j+1]) + board[i][j]

ans = -int(1e9)
for i in range(N) :
    for j in range(M) :
        ans = max(ans,dpup[i][j]+dpdown[i][j])
print(ans)