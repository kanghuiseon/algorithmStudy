import sys
import heapq
import bisect as bs
read = sys.stdin.readline


# def bisrch(left,right,n) :

#     while left <= right :
#         mid = (left + right) // 2
#         if Ks[mid] > n : 
#             right = mid - 1
#         else :
#             left = mid + 1
#     return left - 1


L,K,C = map(int,read().split())
Ks = list(map(int,read().split()))

cuts, pq = [],[]
heapq.heappush(pq,(L,0,L))
Ks.sort()
cnt = 0
while pq : 

    if cnt == C : break

    _, L, R = heapq.heappop(pq)
    cut = bs.bisect_left(Ks,L+R//2)
    cuts.append(Ks[cut])

    heapq.heappush(pq,(-(Ks[cut]-L),L,cut))
    heapq.heappush(pq,(-(R-Ks[cut]),cut,R))
    
    del Ks[cut]
    cnt += 1

# cuts.sort()
ans,_,_ = heapq.heappop(pq)
print(-ans,cuts[0])











