from collections import deque

def bfs() :
    # global cnt
    q = deque()
    # cnt += 1
    q.append((0,0,1)) # x,y,Break
    visited[0][0][1] = 1
    while q :
        cx,cy,B = q.popleft()
        if cx == N-1 and cy == M-1 :
            return visited[cx][cy][B]
        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nx,ny = cx+dx, cy+dy
            
            if 0 <= nx < N and 0 <= ny < M :
                if board[nx][ny] == '0' and visited[nx][ny][B] == 0 : 
                    cnt += 1
                    visited[nx][ny][B] = visited[cx][cy][B] + 1
                    q.append((nx,ny,B))
                elif board[nx][ny] == '1' and B :
                    cnt += 1
                    visited[nx][ny][0] = visited[cx][cy][B] + 1
                    q.append((nx,ny,0))

    return -1

# cnt = 0
N,M = map(int,input().split())
board = [input() for _ in range(N)]
visited = [[[0]*2 for _ in range(M)] for _ in range(N)]
print(bfs())
# print(cnt)