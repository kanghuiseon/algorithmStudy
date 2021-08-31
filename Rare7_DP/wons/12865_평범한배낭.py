import sys

read = sys.stdin.readline

N,K = map(int,read().split())
WV = [list(map(int,read().split())) for _ in range(N)]
dp = [[0]*(K+1) for _ in range(N+1)]

for i in range(N) :
    for j in range(K+1) :
        if j >= WV[i][0] :
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-WV[i][0]]+WV[i][1])
        else :
            dp[i][j] = dp[i-1][j]

print(dp[N-1][K])