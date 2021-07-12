import sys
from collections import deque
read = sys.stdin.readline

def bfs() :
    q = deque()
    q.append(0)

    while q :
        cur = q.popleft()

        if visited[cur] == 1 :continue
        visited[cur] = 1

        for i in range(N+2) :
            if board[cur][i] == 1 and visited[i] == 0 :
                q.append(i)

T = int(read())
for _ in range(T) :
    N = int(read())
    node = [list(map(int,read().split())) for _ in range(N+2)]
    board = [[0] * (N+2) for _ in range(N+2)] 
    for i in range(N+2) :
        for j in range(N+2) :
            if i == j : continue
            if abs(node[i][0]-node[j][0]) + abs(node[i][1]-node[j][1]) <= 1000 :
                board[i][j] = 1
                board[j][i] = 1

    visited = [0 for _ in range(N+2)]
    bfs()

    if visited[-1] == 1 :
        print("happy")
    else :
        print("sad")