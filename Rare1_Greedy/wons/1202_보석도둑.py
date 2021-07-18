import sys
import heapq

read = sys.stdin.readline

N,K = map(int,read().split())
gem,bag = [],[]

for _ in range(N) :
    gem.append(list(map(int,read().split())))
for _ in range(K) :
    bag.append(int(read()))

gem.sort()
bag.sort()

j,ans = 0,0
pq = []
for i in range(K) :
    while(j<N and bag[i] >= gem[j][0]) :  
        heapq.heappush(pq,-gem[j][1])
        j += 1
    if pq :
        ans += (-heapq.heappop(pq))

print(ans)