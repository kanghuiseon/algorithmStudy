import sys
from typing import DefaultDict

read = sys.stdin.readline

def find(x) :
    if par[x] == x : return par[x]
    else :
        par[x] = find(par[x])
        return par[x]

def merge(x,y) :
    p_x = find(x)
    p_y = find(y)
    if p_x == p_y : return

    par[p_x] = p_y 

N,M = map(int,read().split())
par = [i for i in range(N+1)]
sex = [0] + list(read().split())
adjs = []
for i in range(M) :
    u,v,d = map(int,read().split())
    adjs.append([d,u,v])
adjs.sort()

ans = 0
for d,u,v in adjs :
    if sex[u] == sex[v] or find(u) == find(v) : continue
    merge(u,v)
    ans += d

s = 1
for i in range(1,N+1) :
    if find(s) != find(i) :
        print(-1)
        sys.exit()

print(ans)


