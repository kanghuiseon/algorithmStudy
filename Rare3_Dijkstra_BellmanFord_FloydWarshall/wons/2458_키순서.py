import sys
'''
taller + shorter == N-1 임을 이용해서 풀었다.
'''
read =sys.stdin.readline

def tDfs(cur) :
    global T
    visited[cur] = 1
    for nx in taller[cur] :
        if visited[nx] != 0 : continue
        T += 1
        tDfs(nx)

def sDfs(cur) :
    global S
    visited[cur] = 1
    for nx in shorter[cur] :
        if visited[nx] != 0 : continue
        S += 1
        sDfs(nx)

N,M = map(int,read().split())
taller = [[] for _ in range(N+1)]
shorter = [[] for _ in range(N+1)]
for _ in range(M) :
    x,y = map(int,read().split())
    taller[x].append(y)
    shorter[y].append(x)

ans = 0
for i in range(1,N+1) :
    T = S = 0

    visited = [0 for _ in range(N+1)]
    tDfs(i)

    visited = [0 for _ in range(N+1)]
    sDfs(i)

    if T + S == N-1 :
        ans += 1

print(ans)