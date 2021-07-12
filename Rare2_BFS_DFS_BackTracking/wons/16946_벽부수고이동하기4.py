import sys
from collections import deque

read =sys.stdin.readline

def bfs(x,y) :
    q = deque()
    q.append((x,y))
    res = 0
    while q :
        cx,cy = q.popleft()
        if visited[cx][cy] == 1 : continue
        visited[cx][cy] = 1
        groups[cx][cy] = cnt
        res += 1
        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nx,ny = cx+dx, cy+dy

            if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == 0 and visited[nx][ny] == 0 :
                q.append((nx,ny))
    return res

def getCnt(x,y) :
    group = set()
    for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
        nx,ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < M and groups[nx][ny] != 0 :
            group.add(groups[nx][ny])
    cnt = 1
    for g in group :
        cnt += zeroCnt[g]

    return cnt % 10

N,M = map(int,read().split())
board = [list(map(int,*[read().rstrip()])) for _ in range(N)]
groups = [[0] * M for _ in range(N)]
visited = [[0] * M for _ in range(N)]
cnt = 1
zeroCnt = {}
for i in range(N) :
    for j in range(M) :
        if board[i][j] == 0 and visited[i][j] == 0: 
            res = bfs(i,j)
            zeroCnt[cnt] = res 
            cnt += 1

ans = [[0] * M for _ in range(N)]
for i in range(N) :
    for j in range(M) :
        if board[i][j] == 1 :
            ans[i][j] = getCnt(i,j)
        print(ans[i][j],end='')
    print()