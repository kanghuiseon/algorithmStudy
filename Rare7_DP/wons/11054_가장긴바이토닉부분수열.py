import sys 

read = sys.stdin.readline

N = int(read())
seq = list(map(int,read().split()))

dpfor = [1 for _ in range(N)]
dpback = [1 for _ in range(N)]

for i in range(N) :
    for j in range(i+1,N) :
        if seq[i] < seq[j] and dpfor[j] < dpfor[i] + 1 :
            dpfor[j] = dpfor[i] + 1

for i in range(N-1,-1,-1) :
    for j in range(N-1,i,-1) :
        if seq[i] > seq[j] and dpback[i] < dpback[j] + 1 :
            dpback[i] = dpback[j] + 1

ans = -1
for i in range(N) :
    ans = max(ans,dpfor[i]+dpback[i]-1)

print(ans)