import sys
from collections import deque

read = sys.stdin.readline

def bfs() :
    q = deque()
    q.append([0,0,K]) # x,y,Jump
    visited = [[[0 for _ in range(K+1)] for _ in range(W)] for _ in range(H)]

    while q :
        cx,cy,J = q.popleft()
        
        if cx == H-1 and cy == W-1 :
            return visited[cx][cy][J] 
        
        if J : 
            for dx,dy in [[-1,-2],[-2,-1],[-2,1],[-1,2],[1,-2],[2,-1],[2,1],[1,2]] :
                nx,ny = cx+dx, cy+dy
                if 0 <= nx < H and 0 <= ny < W and board[nx][ny] == 0 and visited[nx][ny][J-1] == 0: 
                    visited[nx][ny][J-1] = visited[cx][cy][J] + 1
                    q.append([nx,ny,J-1])

        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nx,ny = cx+dx, cy+dy
            if 0 <= nx < H and 0 <= ny < W and board[nx][ny] == 0 and visited[nx][ny][J] == 0 :
                visited[nx][ny][J] = visited[cx][cy][J] + 1
                q.append([nx,ny,J])

    return -1

K = int(read())
W,H = map(int,read().split())
board = [list(map(int,read().split())) for _ in range(H)]

print(bfs())