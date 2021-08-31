import sys 

read =sys.stdin.readline

def dfs(cnt,idx,r) :
    global ans,board
    if cnt == r :
        for i in range(1,N+1) :
            tmp = i
            for j in range(1,H+1) :
                if board[j][tmp] == 1 :
                    tmp += 1
                elif board[j][tmp-1] == 1 :
                    tmp -= 1
            if tmp != i :
                return
        ans = cnt
        return 
        
    for i in range(idx,H+1) :
        for j in range(1,N) :
            if board[i][j] : continue
            elif j-1 >= 1 and board[i][j-1] == 1 : continue
            elif j+1 <= N and board[i][j+1] == 1 : continue
            else :
                board[i][j] = 1
                dfs(cnt+1,i,r)
                board[i][j] = 0
        
N,M,H = map(int,read().split())
board = [[0] * (N+1) for _ in range(H+1)]
for _ in range(M) :
    a,b = map(int,read().split())
    board[a][b] = 1

ans = -1
for r in range(4) :
    dfs(0,1,r)
    if ans != -1 :
        print(ans)
        break

if ans == -1 :
    print(ans)
