import sys 
from collections import deque
read = sys.stdin.readline


def bfs(x,y,r) :
    global adjs,visitedK
    q = deque()
    q.append([0,x,y])
    visited = [[0] * N for _ in range(N)]
    visited[x][y] = 1
    k = 0
    while q :
        c,cx,cy = q.popleft()

        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nx = cx + dx
            ny = cy + dy

            if board[nx][ny] != 1 and visited[nx][ny] == 0 :
                q.append([c+1,nx,ny]) 
                visited[nx][ny] = 1

                if board[nx][ny] >= 2 :
                    adjs.append([c+1,r,board[nx][ny]])
                    k += 1

    return k == M 
    
def find(x) :
    if par[x] == x : return par[x]
    else :
        par[x] = find(par[x])
        return par[x]

def merge(x,y) :
    p_x = find(x)
    p_y = find(y)
    if p_x == p_y : return

    par[p_x] = p_y 


N,M = map(int,read().split())
board = [list(*read().split()) for _ in range(N)]

cnt = 2
for i in range(N) :
    for j in range(N) :
        if board[i][j] == 'S' or board[i][j] == 'K' :
            board[i][j] = cnt
            cnt += 1
        else :
            board[i][j] = int(board[i][j])

adjs = []
for i in range(N) :
    for j in range(N) :
        if board[i][j] >= 2 :
            if not bfs(i,j,board[i][j]) :
                print(-1)
                sys.exit()

par = [i for i in range(cnt)]
adjs.sort()
ans = 0
for c,x,y in adjs :
    if find(x) == find(y) : continue
    merge(x,y)
    ans += c
print(ans)



