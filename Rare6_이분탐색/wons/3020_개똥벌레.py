import sys
from bisect import bisect_left
read = sys.stdin.readline


def bisrch(low,high,target,arr) :
    while low <= high :
        mid = (low+high) // 2

        if arr[mid] < target :
            low = mid + 1
        else :
            high = mid - 1
    return high + 1

N,H = map(int,read().split())
bottom,top = [],[]
for i in range(N) :
    tmp = int(read())
    if i % 2 == 0 :
        bottom.append(tmp)
    else :
        top.append(tmp)

bottom.sort()
top.sort()

ans,cnt = N,0
for h in range(1,H+1) :
    cntB = len(bottom) - bisect_left(bottom,h)
    cntT = len(top) -  bisect_left(top,H-h+1)
    
    # cntB = len(bottom) - bisrch(0,len(bottom)-1,h,bottom)
    # cntT = len(top) - bisrch(0,len(top)-1,H-h+1,top)
    
    if ans == cntB + cntT :
        cnt += 1
    
    elif ans > cntB + cntT : 
        cnt = 1
        ans = cntB + cntT

print(ans,cnt)

