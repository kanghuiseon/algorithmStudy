import sys
from bisect import bisect_left as lower_bound

read = sys.stdin.readline

def bisrch(n) :
    
    low = 0; high = len(lis)

    while low <= high :
        mid = (low+high) // 2
        if lis[mid] < n :
            low = mid + 1
        else :
            high = mid - 1
    return high + 1

N = int(read())
seq = list(map(int,read().split()))
lis = []

for n in seq :
    if not lis or lis[-1] < n :
        lis.append(n)
    else :
        # idx = bisrch(n)
        idx = lower_bound(lis,n)
        lis[idx] = n

print(len(lis))


