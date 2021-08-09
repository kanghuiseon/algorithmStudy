import sys
import math

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

def dist(x,y) :
    return math.sqrt((x[0]-y[0])**2 + (x[1]-y[1])**2)

N,M = map(int,read().split())
par = [i for i in range(N+1)]
pts = [list(map(int,read().split())) for _ in range(N)]

for _ in range(M) :
    x,y = map(int,read().split())
    merge(x,y)

adjs = []
for i in range(N) :
    for j in range(i+1,N) :
        adjs.append([dist(pts[i],pts[j]),i+1,j+1])
adjs.sort()

ans = 0.0
for c,x,y in adjs :
    if find(x) == find(y) : continue
    merge(x,y) 
    ans += c
print("{:.2f}".format(ans)) 