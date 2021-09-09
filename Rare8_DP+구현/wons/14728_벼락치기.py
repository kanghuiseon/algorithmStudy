import sys

read = sys.stdin.readline

N,T = map(int,read().split())
KS = [list(map(int,read().split())) for _ in range(N)]
dp = [[0]*(T+1) for _ in range(N)]
for i in   range(N) :
    for j in range(1,T+1) :
        if j >= KS[i][0] :
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-KS[i][0]]+KS[i][1])
        else :
            dp[i][j] = dp[i-1][j]

print(dp[N-1][T])