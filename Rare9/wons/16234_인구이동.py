import sys
from collections import deque

read = sys.stdin.readline

def bfs(x,y) :
    q =deque()
    q.append([x,y])
    visited[x][y] = 1
    roi = [[x,y]]
    while q : 
        cx,cy = q.popleft()

        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nx = cx + dx
            ny = cy + dy 

            if nx < 0 or nx >= N or ny < 0 or ny >= N or visited[nx][ny] != 0 : continue

            if L <= abs(board[cx][cy] - board[nx][ny]) <= R :
                visited[nx][ny] = 1
                roi.append([nx,ny])
                q.append([nx,ny])
    return roi

N,L,R = map(int,read().split())
board = [list(map(int,read().split())) for _ in range(N)]

ans = 0
while True :
    visited = [[0] * N for _ in range(N)]
    isOpen = False
    for i in range(N) :
        for j in range(N) :
            if visited[i][j] == 0 :
                roi = bfs(i,j)
                
                if len(roi) > 1 : 
                    isOpen = True
                    mean = sum([board[x][y] for x,y in roi]) // len(roi)
                    for x,y in roi :
                        board[x][y] = mean
    if not isOpen :
        break 
    ans += 1
print(ans)


