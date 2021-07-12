
def dfs(depth) :
    global ans

    if depth == N :
        ans += 1
        return
    
    for i in range(N) :
        if not col[i] and not diag1[i+depth] and not diag2[(i-depth)+N] :
            col[i] = diag1[i+depth] = diag2[(i-depth)+N] = True
            dfs(depth+1) 
            col[i] = diag1[i+depth] = diag2[(i-depth)+N] = False



ans = 0
N = int(input())
col,diag1,diag2 = [False]*N , [False]*(2*N+1) , [False]*(2*N+1)
board = [[0] * N for _ in range(N)]
dfs(0)

print(ans)