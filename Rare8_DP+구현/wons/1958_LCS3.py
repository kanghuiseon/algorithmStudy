import sys

read = sys.stdin.readline

A = read().strip(); An = len(A)
B = read().strip(); Bn = len(B)
C = read().strip(); Cn = len(C)

dp = [[[0]*(Cn+1) for _ in range(Bn+1)] for _ in range(An+1)]

for i in range(An) :
    for j in range(Bn) :
        for k in range(Cn) :
            if A[i] == B[j] == C[k] :
                dp[i+1][j+1][k+1] = dp[i][j][k] + 1
            else :
                dp[i+1][j+1][k+1] = max([dp[i+1][j][k],dp[i][j+1][k],dp[i][j][k+1],dp[i+1][j+1][k],dp[i+1][j][k+1],dp[i][j+1][k+1]])

print(dp[An][Bn][Cn])