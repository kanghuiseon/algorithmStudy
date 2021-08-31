from collections import deque

def bfs() :
    q = deque()
    q.append([0,0,K])
    visited[0][0][K] = 1
    while q :
        cx,cy,B = q.popleft()
        if cx == N-1 and cy == M-1 :
            return visited[cx][cy][B]
        for dx,dy in [[-1,0],[0,-1],[1,0],[0,1]] :
            nx,ny = cx+dx, cy+dy
            
            if 0 <= nx < N and 0 <= ny < M and visited[nx][ny][B] == 0 :
                if board[nx][ny] == 0 : 
                    visited[nx][ny][B] = visited[cx][cy][B] + 1
                    q.append([nx,ny,B])
                elif board[nx][ny] == 1 and B and visited[nx][ny][B-1] == 0:
                    visited[nx][ny][B-1] = visited[cx][cy][B] + 1
                    q.append([nx,ny,B-1])

    return -1

N,M,K = map(int,input().split())
board = [list(map(int,[*input()])) for _ in range(N)]
visited = [[[0 for _ in range(K+1)] for _ in range(M)] for _ in range(N)]
print(bfs())