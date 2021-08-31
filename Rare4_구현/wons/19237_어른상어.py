import sys

read = sys.stdin.readline

N,M,K = map(int,read().split())
board = [list(map(int,read().split())) for _ in range(N)]
dir_ = list(map(int,read().split()))
shark = [[] for _ in range(M+1)]
shark_move = [[0] for _ in range(M+1)]
perfume = []
for i in range(N) :
    for j in range(N) :
        if board[i][j] != 0 :
            shark[board[i][j]] = [i,j,dir_[board[i][j]-1]]

for i in range(1,M+1) :
    for _ in range(4) :
        a,b,c,d = map(int,read().split())
        shark_move[i].append([a,b,c,d])

T = 0
live = [1 for _ in range(M+1)]
shark_cnt = M
while True :
    if shark_cnt == 1 or T > 1000 : 
        break
    tmp = []
    for i in range(1,M+1) : 
        if live[i] == 0 : continue
        sx,sy,_ = shark[i] 
        tmp.append([sx,sy,i])
    perfume.append(tmp)

    board = [[0] * N for _ in range(N)]
    for t in perfume :
        for px,py,i in t :
            board[px][py] = i
    
    for i in range(1,M+1) :
        if live[i] == 0 : continue
        sx,sy,d = shark[i]
        isMove = False
        for dx in shark_move[i][d] :
            if dx == 1 and sx-1 >= 0 and board[sx-1][sy] == 0:
                shark[i] = [sx-1,sy,dx]; isMove = True; break
            elif dx == 2 and sx+1 < N and board[sx+1][sy] == 0:
                shark[i] = [sx+1,sy,dx]; isMove = True; break
            elif dx == 3 and sy-1 >= 0 and board[sx][sy-1] == 0:
                shark[i] = [sx,sy-1,dx]; isMove = True; break
            elif dx == 4 and sy+1 < N and board[sx][sy+1] == 0:
                shark[i] = [sx,sy+1,dx]; isMove = True; break
        if not isMove : 
            for dx in shark_move[i][d] :
                if dx == 1 and sx-1 >= 0 and board[sx-1][sy] == i:
                    shark[i] = [sx-1,sy,dx]; break
                elif dx == 2 and sx+1 < N and board[sx+1][sy] == i:
                    shark[i] = [sx+1,sy,dx]; break
                elif dx == 3 and sy-1 >= 0 and board[sx][sy-1] == i:
                    shark[i] = [sx,sy-1,dx]; break
                elif dx == 4 and sy+1 < N and board[sx][sy+1] == i:
                    shark[i] = [sx,sy+1,dx]; break

    for i in range(1,M+1) :
        if live[i] == 0 : continue
        for j in range(i+1,M+1) :
            if shark[i][:2] == shark[j][:2] and live[j] :
                live[j] = 0
                shark_cnt -= 1


    T += 1

    if T >= K :
        perfume.pop(0)

print(T if T != 1001 else -1)