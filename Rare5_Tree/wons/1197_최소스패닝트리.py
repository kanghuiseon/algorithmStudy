import sys

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

V,E = map(int,read().split())
par = [i for i in range(V+1)]
adjs = []
for _ in range(E) :
    x,y,c = map(int,read().split())
    adjs.append([c,x,y])
adjs.sort()

ans = 0
for c,x,y in adjs :
    if find(x) == find(y) : continue
    ans += c
    merge(x,y)
print(ans)