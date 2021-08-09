import sys

read = sys.stdin.readline

def find(x) :
    if par[x] == D :
        return True
    if par[x] == -1 :
        return False
    else :
        return find(par[x])

N = int(read())
par = list(map(int,read().split()))
D = int(read())

child = [0 for _ in range(N)]
for i in range(N) :
    if par[i] == -1 or i == D : continue
    child[par[i]] += 1

ans = 0
for i in range(N) :
    if i == D or find(i) : continue
    if child[i] == 0 :
        ans += 1
print(ans)