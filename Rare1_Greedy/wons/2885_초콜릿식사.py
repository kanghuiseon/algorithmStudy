
K = int(input())

N = 1
while True :
    if N >= K : break
    N *= 2
print(N,end=' ')

cnt = 0
while K :
    while N > K :
        N = int(N//2)
        cnt += 1
    K -= N
print(cnt)
