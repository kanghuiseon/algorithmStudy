import sys
def find(x) :
    global par
    if par[x] == x : return par[x]
    else :
        par[x] = find(par[x])
        return par[x]

def merge(x,y) :
    global par
    p_x = find(x)
    p_y = find(y)
    if p_x == p_y : return
    if p_x > p_y :
        p_x,p_y = p_y,p_x
    par[p_y] = p_x

def checkSpan(cost) :
    global ansC,ansS,span,par
    if ansC <= cost : return
    isSpan = True
    par = [i for i in range(N+1)]
    for x,y in span :
        merge(x,y)
    for i in range(2,N+1) :
        if find(i) != find(1) :
            return False
    
    if isSpan :
        ansC = cost
        ansS = span.copy()

def dfs(cur,cnt,cost) :
    global span
    if cnt == N-1 : 
        checkSpan(cost)
        return
    if cur >= M : return 

    dfs(cur+1,cnt,cost)
    c,x,y = adjs[cur]
    if b[x-1] and b[y-1] : 
        span.append([x,y])
        b[x-1] -= 1; b[y-1] -= 1
        dfs(cur+1,cnt+1,cost+c)
        span.pop()
        b[x-1] += 1; b[y-1] += 1

N,M = map(int,input().split())
if N == 1 :
    print("YES")
    sys.exit()
b = list(map(int,input().split()))
par = [i for i in range(N+1)]
adjs = []
for _ in range(M) :
    x,y,c = map(int,input().split())
    if x > y : 
        x,y = y,x
    adjs.append([c,x,y])

ansC,ansS,span = int(1e9),[],[]
dfs(0,0,0)
if ansS :
    print("YES")
    for x,y in ansS :
        print(x,y)
else :
    print("NO")
