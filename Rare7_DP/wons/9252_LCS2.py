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
ans = dp[An][Bn]

ret = ""
while dp[An][Bn] != 0 :
    if dp[An][Bn] == dp[An-1][Bn] : An -= 1
    elif dp[An][Bn] == dp[An][Bn-1] : Bn -= 1
    else :
        ret = A[An-1] + ret
        An -= 1; Bn -= 1

print(ans)
print(ret)