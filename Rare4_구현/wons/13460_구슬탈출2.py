import sys
from collections import deque

read = sys.stdin.readline

def bfs() :
    # visitedR = [[0] * M for _ in range(N)]
    # visitedB = [[0] * M for _ in range(N)]
    visited = [[[[0] * M for _ in range(N)] for _ in range(M)] for _ in range(N)]

    q = deque()
    q.append([bx,by,rx,ry,1])
    while q :
        cBx,cBy,cRx,cRy,d = q.popleft()
        
        if d > 10 : break

        if visited[cBx][cBy][cRx][cRy] == 1 : continue
        visited[cBx][cBy][cRx][cRy] = 1
        # if visitedB[cBx][cBy] == 1 and visitedR[cRx][cRy] == 1 : continue
        # visitedB[cBx][cBy] = visitedR[cRx][cRy] = 1

        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nBx,nBy,nRx,nRy = cBx,cBy,cRx,cRy
            
            moveB = 0
            while board[nBx+dx][nBy+dy] != '#' and board[nBx][nBy] != 'O' :
                nBx += dx; nBy += dy
                moveB += 1

            moveR = 0
            while board[nRx+dx][nRy+dy] != '#' and board[nRx][nRy] != 'O' :
                nRx += dx; nRy += dy
                moveR += 1

            if board[nBx][nBy] == 'O' : continue
            if board[nRx][nRy] == 'O' :
                print(d)
                return 

            if nRx == nBx and nRy == nBy :
                if moveR > moveB : nRx -= dx; nRy -= dy
                else :  nBx -= dx; nBy -= dy 

            if visited[nBx][nBy][nRx][nRy] == 0 : 
                q.append([nBx,nBy,nRx,nRy,d+1])
            # if visitedB[nBx][nBy] == 0 or visitedR[nRx][nRy] == 0 :
            #     q.append([nBx,nBy,nRx,nRy,d+1])
           
    print(-1)
    return

N,M = map(int,read().split())
board = []
bx,by,rx,ry = 0,0,0,0

for i in range(N) :
    board.append(list(read().strip()))
    for j in range(M) :
        if board[i][j] == 'B' : 
            bx,by = i,j
        elif board[i][j] == 'R' :
            rx,ry = i,j

bfs()