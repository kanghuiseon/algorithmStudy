import sys

read = sys.stdin.readline

A = read().strip(); An = len(A)
B = read().strip(); Bn = len(B)
dp = [[0]*(Bn+1) for _ in range(An+1)]

for i in range(An) :
    for j in range(Bn) :
        if A[i] == B[j] :
            dp[i+1][j+1] = dp[i][j] + 1
        else :
            dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j])

print(dp[An][Bn])