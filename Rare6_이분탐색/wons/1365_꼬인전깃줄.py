import sys
from bisect import bisect_left as lower_bound

read = sys.stdin.readline

N = int(read())
seq = list(map(int,read().split()))
lis = []

for n in seq :
    if not lis or lis[-1] < n :
        lis.append(n)
    else :
        idx = lower_bound(lis,n)
        lis[idx] = n

print(len(seq)-len(lis))


