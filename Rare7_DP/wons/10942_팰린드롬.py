import sys

read = sys.stdin.readline

def getPal() :
    for i in range(N) :
        dp[i][i] = 1
        left = i-1; right = i+1
        while 0 <= left and right < N :
            if seq[left] != seq[right] : break
            dp[left][right] = 1
            left -= 1; right += 1
    
    for i in range(N) :
        left = i; right = i+1
        while 0 <= left and right < N :
            if seq[left] != seq[right] : break
            dp[left][right] = 1
            left -= 1; right += 1

N = int(read())
seq = list(map(int,read().split()))
M = int(read())
qs = [list(map(int,read().split())) for _ in range(M)]
dp = [[0]*(N) for _ in range(N)]
getPal()
for st,ed in qs :
    print(dp[st-1][ed-1])

