# from collections import deque

def bfs() :

    q = set([(0,0,board[0][0])]) # x,y,path
    res = 0
    while q :
        cx,cy,path = q.pop()
        res = max(res,len(path))
        
        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nx,ny = cx+dx, cy+dy
            if 0 <= nx < R and 0 <= ny < C and board[nx][ny] not in path :
                q.add((nx,ny,path+board[nx][ny]))

    return res

R,C = map(int,input().split())
board = [list(input()) for _ in range(R)]

print(bfs())

