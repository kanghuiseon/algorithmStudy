import sys
import heapq

read = sys.stdin.readline
INF = int(1e9)
def dji() :
    pq = []
    dist = [[INF]* N for _ in range(N)]
    heapq.heappush(pq,[board[0][0],0,0])
    dist[0][0] = board[0][0]
    while pq :
        cost,cx,cy = heapq.heappop(pq)
        
        if dist[cx][cy] < cost :  continue

        for dx,dy in [[-1,0],[1,0],[0,1],[0,-1]] :
            nx = cx + dx
            ny = cy + dy
            if 0 <= nx < N and 0 <= ny < N and dist[nx][ny] > cost + board[nx][ny] :
                heapq.heappush(pq,[cost+board[nx][ny],nx,ny])
                dist[nx][ny] = cost+board[nx][ny]

    return dist[N-1][N-1]

cnt = 1
while True :
    N = int(read())
    if N == 0 : break

    board = [list(map(int,read().split())) for _ in range(N)]
    print("Problem {}: {}".format(cnt,dji()))
    cnt += 1
