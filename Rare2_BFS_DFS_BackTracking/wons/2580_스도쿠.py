import sys

def dfs(depth) :
    if depth == len(zeros) :
        for row in board :
            print(*row) 
        sys.exit()
    
    cx,cy = zeros[depth]
    candi = [1 for _ in range(10)]
    for i in range(9) :
        candi[board[cx][i]] = 0
        candi[board[i][cy]] = 0
    
    for i in range((cx//3)*3,(cx//3)*3+3) :
        for j in range((cy//3)*3,(cy//3)*3+3) :
            candi[board[i][j]] = 0
        
    for i in range(1,10) :
        if candi[i] == 0 : continue
        board[cx][cy] = i
        dfs(depth+1)
        board[cx][cy] = 0


board = [list(map(int,input().split())) for _ in range(9)]
zeros = []
for i in range(9) :
    for j in range(9) :
        if board[i][j] == 0 :
            zeros.append([i,j])

dfs(0)