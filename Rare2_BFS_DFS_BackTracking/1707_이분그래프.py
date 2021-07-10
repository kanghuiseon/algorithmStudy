from os import replace
import sys
from collections import deque
read = sys.stdin.readline

def bfs(cur) :

    q = deque()
    q.append(cur)
    visited[cur] = 1
    while q :
        cur = q.popleft()
        for next in adjs[cur] :
            if visited[next] == 0 :
                q.append(next)
                visited[next] = -1 * visited[cur] # 이웃 한 애 색칠
            if visited[next] == visited[cur]: # 같은 색이면 이분 그래프 아님
                return False
    return True

T = int(read())
for _ in range(T) :
    V,E = map(int,read().split())
    adjs = [[] for _ in range(V+1)]
    visited = [0 for _ in range(V+1)]

    for _ in range(E) :
        x,y = map(int,read().split())
        adjs[x].append(y)
        adjs[y].append(x)
    
    ans = True
    for v in range(1,V+1) :
        if visited[v] == 0 :
            if not bfs(v) :
                ans = False
                break
    
    if ans : print("YES")
    else : print("NO")

