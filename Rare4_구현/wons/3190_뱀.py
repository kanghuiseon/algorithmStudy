import sys

read = sys.stdin.readline

N = int(read()); K = int(read())
board = [[0] * (N+1) for _ in range(N+1)]
turn = [0 for _ in range(10001)]
for _ in range(K) :
    x,y = map(int,read().split())
    board[x][y] = 1
L = int(read())
for _ in range(L) :
    t,d = read().split()
    if d == 'D' : turn[int(t)] = 1
    else : turn[int(t)] = -1

T,D,L = 0,'R',1
cx,cy = 1,1
bam = [[1,1]]
while True :
    nx,ny = cx,cy
    if D == 'R' : ny += 1
    elif D == 'L' : ny -= 1
    elif D == 'U' : nx -= 1
    else : nx += 1

    isOver = False
    if 0 >= nx or nx > N or 0 >= ny or ny > N : isOver = True
    for bx,by in bam :
        if bx == nx and by == ny : 
            isOver = True
            break
    if isOver : break


    if board[nx][ny] == 1 : 
        bam.append([nx,ny])
        board[nx][ny] = 0
    else :
        bam.append([nx,ny])
        bam.pop(0)
    
    cx,cy = nx,ny
    T += 1

    if turn[T] == 1 :
        if D == 'R' : D = 'D'
        elif D == 'L' : D = 'U'
        elif D == 'D' : D = 'L'
        else : D = 'R'
    elif turn[T] == -1 :
        if D == 'R' : D = 'U'
        elif D == 'L' : D = 'D'
        elif D == 'D' : D = 'R'
        else : D = 'L'
    
print(T+1)