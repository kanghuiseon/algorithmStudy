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

N = int(read())
M = int(read())
adjs = [list(map(int,read().split())) for _ in range(N)]
par = [i for i in range(N)]
for i in range(N) :
    for j in range(N) :
        if adjs[i][j] == 1 :
            merge(i,j)
course = list(map(int,read().split()))
for i in range(1,M) :
    if find(course[i-1]-1) != find(course[i]-1) :
        print("NO")
        sys.exit()
print("YES")