import sys
from itertools import permutations

read = sys.stdin.readline

N,K = map(int,read().split())
dp = [[1]*(K+1) for _ in range(N+1)]

for i in range(1,K+1) :
    dp[1][i] = i


for i in range(2,N+1) :
    for j in range(2,K+1) :
        dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000

print(dp[N][K])

