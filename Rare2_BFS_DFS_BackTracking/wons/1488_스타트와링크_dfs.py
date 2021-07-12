import sys

read =sys.stdin.readline

def dfs(idx,cnt) :
    global ans
    if cnt == N // 2 :
        t1,t2 = 0,0
        for i in range(N) :
            for j in range(N) :
                if team[i] == 1 and team[j] == 1 :
                    t1 += board[i][j]
                elif team[i] == 0 and team[j] == 0 :
                    t2 += board[i][j]
        ans = min(ans,abs(t1-t2))
        return

    for i in range(idx,N) :
        if team[i] : continue
        team[i] = 1
        dfs(i+1,cnt+1)
        team[i] = 0


N = int(read())
board = [list(map(int,read().split())) for _ in range(N)]
team = [0 for _ in range(N)]
ans = int(1e9)
dfs(0,0)
print(ans)




