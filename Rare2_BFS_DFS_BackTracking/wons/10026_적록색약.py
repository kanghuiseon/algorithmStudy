from collections import deque
import sys

read = sys.stdin.readline

def bfs(x,y,C) :
    q = deque()
    q.append((x,y))

    while q :
        cx,cy = q.popleft()

        if visited[cx][cy] == 1 : continue
        visited[cx][cy] = 1

        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nx,ny = cx+dx, cy+dy
            if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == 0 and board[nx][ny] == C :
                q.append((nx,ny))
                
def bfsRG(x,y,C) :
    q = deque()
    q.append((x,y))

    while q :
        cx,cy = q.popleft()

        if visited[cx][cy] == 1 : continue
        visited[cx][cy] = 1

        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nx,ny = cx+dx, cy+dy
            if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == 0 :
                if (C == "R" or C == "G") and (board[nx][ny] == "R" or board[nx][ny] == "G") :
                    q.append((nx,ny))
                elif board[nx][ny] == C :
                    q.append((nx,ny))


N = int(read())
board = [list(read().rstrip()) for _ in range(N)]
visited = [[0] * N for _ in range(N)]
RG,RGB = 0,0 
for i in range(N) :
    for j in range(N) :
        if visited[i][j] == 0 :
            bfs(i,j,board[i][j])
            RGB += 1

visited = [[0] * N for _ in range(N)]
for i in range(N) :
    for j in range(N) :
        if visited[i][j] == 0 :
            bfsRG(i,j,board[i][j])
            RG += 1

print(RGB,RG)