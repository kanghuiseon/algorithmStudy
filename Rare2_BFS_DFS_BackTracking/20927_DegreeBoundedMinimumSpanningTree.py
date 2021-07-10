

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

def checkSpan(cost) :
    global ansC,ansS
    if ansC <= cost : return
    isSpan = True
    par = [i for i in range(N+1)]
    for x,y in span :
        merge(x,y)
    for c,x,y in adjs :
        if find(x) != find(y) :
            isSpan = False
            break
    if isSpan :
        ansC = cost
        ansS = span.copy()

def dfs(cur,cnt,cost) :
    global ansC,ansS
    if cnt == N-1 : 
        checkSpan(cost)
        return
    if cur == M : return 

    dfs(cur+1,cnt,cost)
    c,x,y = adjs[cur]
    if b[x-1] and b[y-1] : 
        span.append([x,y])
        b[x-1] -= 1; b[y-1] -= 1
        dfs(cur+1,cnt+1,cost+c)
        span.pop()
        b[x-1] += 1; b[y-1] += 1

N,M = map(int,input().split())
b = list(map(int,input().split()))
par = [i for i in range(N+1)]
adjs = []
for _ in range(M) :
    x,y,c = map(int,input().split())
    adjs.append([c,x,y])

ansC,ansS,span = int(1e9),[],[]
dfs(0,0,0)
if ansS :
    print("YES")
    for x,y in ansS :
        print(x,y)
else :
    print("NO")
