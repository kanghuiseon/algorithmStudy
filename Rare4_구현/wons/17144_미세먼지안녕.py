import sys

read = sys.stdin.readline

R,C,T = map(int,read().split())
board = [list(map(int,read().split())) for _ in range(R)]
airU,airD = 0,0
for i in range(R) :
    if board[i][0] == -1 :
        airU,airD = i,i+1
        break

for t in range(T) :
    spread = []
    for i in range(R) :
        for j in range(C) :
            if board[i][j] == 0 : continue
            if board[i][j] < 5 : spread.append([i,j,board[i][j]]); continue

            smog = int(board[i][j]/5)
            cnt = 0
            for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
                nx = i + dx
                ny = j + dy
                if 0 <= nx < R and 0 <= ny < C and board[nx][ny] != -1 :
                    cnt += 1
                    spread.append([nx,ny,smog])

            spread.append([i,j,board[i][j]-(smog*cnt)])            
    
    board = [[0] * (C) for _ in range(R)]
    for r,c,smog in spread :
        board[r][c] += smog


    cr,cc,d = airU-1,0,0

    while True :
        if cr == airU and cc == 1 : 
            board[cr][cc] = 0
            break    
        if cr < 0 : cr = airU; d = 3
        if cr == 0 : d = 1
        if cc == C-1 : d = 2
        if cr == airU : d = 3

    
        if d == 0 :
            board[cr][cc] = board[cr-1][cc]
            cr -= 1
        elif d == 1 :
            board[cr][cc] = board[cr][cc+1]
            cc += 1
        elif d == 2 :
            board[cr][cc] = board[cr+1][cc]
            cr += 1
        else :
            board[cr][cc] = board[cr][cc-1]
            cc -= 1

    cr,cc,d = airD+1,0,0
    while True :
        if cr == airD and cc == 1 :
            board[cr][cc] = 0
            break    
        if cr >= R : cr = airD; d = 3
        if cr == R-1 : d = 1
        if cc == C-1 : d = 2
        if cr == airD : d = 3

        if d == 0 :
            board[cr][cc] = board[cr+1][cc]
            cr += 1
        elif d == 1 :
            board[cr][cc] = board[cr][cc+1]
            cc += 1
        elif d == 2 :
            board[cr][cc] = board[cr-1][cc]
            cr -= 1
        else :
            board[cr][cc] = board[cr][cc-1]
            cc -= 1


ans = 2
for row in board :
    ans += sum(row)
print(ans)

