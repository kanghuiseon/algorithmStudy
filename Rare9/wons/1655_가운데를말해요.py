import sys
import heapq

read = sys.stdin.readline

N = int(read())
num = [int(read()) for _ in range(N)]

pqH, pqL = [],[-num[0]]
print(num[0])
for n in num[1:] :
    if n > -pqL[0] : heapq.heappush(pqH,n)
    else : heapq.heappush(pqL,-n)

    if len(pqL) < len(pqH) :
        heapq.heappush(pqL,-heapq.heappop(pqH))
    elif len(pqL)-1 > len(pqH) :
        heapq.heappush(pqH,-heapq.heappop(pqL))

    print(-pqL[0])
