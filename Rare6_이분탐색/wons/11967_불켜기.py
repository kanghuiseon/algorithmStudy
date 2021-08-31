import sys
from collections import deque

read = sys.stdin.readline

def bfs() :
    q = deque()
    q.append([1,1])
    visited = [[0]*(N+1) for _ in range(N+1)]
    ligth   = [[0] *(N+1) for _ in range(N+1)]
    visited[1][1] = 1
    ligth[1][1] = 1
    cnt = 1
    while q :
        cx,cy = q.popleft()

        for rx,ry in board[cx][cy] :
            if ligth[rx][ry] == 1 : continue
            ligth[rx][ry] = 1
            cnt += 1
           
            for dx,dy in [[-1,0],[1,0],[0,1],[0,-1]] :
                nx = rx + dx
                ny = ry + dy

                if 1 <= nx <= N and 1 <= ny <= N and visited[nx][ny] == 1 :
                    q.append([nx,ny])


        for dx,dy in [[-1,0],[1,0],[0,1],[0,-1]] :
            nx = cx + dx
            ny = cy + dy

            if 1 <= nx <= N and 1 <= ny <= N and visited[nx][ny] == 0 and ligth[nx][ny] == 1 :
                q.append([nx,ny])
                visited[nx][ny] = 1

    return cnt

N,M = map(int,read().split())
board = [[[]*(N+1) for _ in range(N+1)] for _ in range(N+1)]
for _ in range(M) :
    x,y,a,b = map(int,read().split())
    board[x][y].append([a,b])

print(bfs())
