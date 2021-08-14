import sys 

read = sys.stdin.readline


def bisrch(low,high) :


    while low < high :
        mid = (low+high) // 2

        ans = 0
        for t in tree :
            if t <= mid : continue
            ans += (t-mid)

        if ans < M :
            high = mid - 1
        else :
            low = mid + 1
    
    return low - 1

N,M = map(int,read().split())
tree = list(map(int,read().split()))

print(bisrch(0,max(tree)))
