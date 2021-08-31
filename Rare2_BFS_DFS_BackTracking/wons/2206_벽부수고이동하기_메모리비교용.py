from collections import deque

def bfs() :
    global cnt
    q = deque()
    cnt += 1
    q.append((0,0,1)) # x,y,Break,Lenght
    visited[0][0] = 1
    while q :
        cx,cy,B = q.popleft()
        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nx,ny = cx+dx, cy+dy
            if 0 <= nx < N and 0 <= ny < M and visited[nx][ny] > visited[cx][cy] :
                if board[nx][ny] == '0' :
                    cnt += 1
                    visited[nx][ny] = visited[cx][cy] + 1
                    q.append((nx,ny,B))
                elif board[nx][ny] == '1' and B :
                    cnt += 1
                    visited[nx][ny] = visited[cx][cy] + 1
                    q.append((nx,ny,0))

cnt = 0   
N,M = map(int,input().split())
board = [input() for _ in range(N)]
visited = [[int(1e9)]*M for _ in range(N)]
    
bfs()
print(cnt)
if visited[N-1][M-1] == int(1e9) :
    print(-1)
else :
    print(visited[N-1][M-1])