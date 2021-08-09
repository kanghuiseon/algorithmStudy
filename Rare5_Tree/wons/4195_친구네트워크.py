import sys

read = sys.stdin.readline
def find(x) :
    if par[x][0] == x : return par[x][0]
    else :
        par[x][0] = find(par[x][0])
        return par[x][0]
def merge(x,y) :
    p_x = find(x)
    p_y = find(y)
    if p_x == p_y : return

    par[p_x][0] = p_y
    par[p_y][1] += par[p_x][1]

T = int(read())
for _ in range(T) :
    F = int(read())
    par = {} # name : [par,child]
    for _ in range(F) :
        x,y = read().strip().split()
        if x not in par :
            par[x] = [x,1]
        if y not in par :
            par[y] = [y,1]
        
        merge(x,y)
        p_y = find(y)
        print(par[p_y][1])