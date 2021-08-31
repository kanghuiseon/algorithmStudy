def deep(x,d) :
    for i in range(d) : x = par[x]
    return x

N = int(input())
tree = input()
x,y = map(int,input().split())

par,depth = [0] * (N+1) , [0] * (N+1)
one,zero = [0] * (2*N+1) , [0] * (2*N+1)
st,node = [0],1

for i,t in enumerate(tree,1) :
    if t == '0' :
        par[node] = st[-1]
        depth[node] = depth[st[-1]] + 1
        zero[i] = node
        st.append(node); node+=1
    else :
        one[i] = st[-1]
        st.pop()

x = zero[x] if tree[x-1] == '0' else one[x]
y = zero[y] if tree[y-1] == '0' else one[y]

x = deep(x,max(0,depth[x]-depth[y]))
y = deep(y,max(0,depth[y]-depth[x]))

while x != y :
    x = par[x]
    y = par[y]

z,o = 0,0
for i in range(2*N+1) :
    if zero[i] == x :
        z = i
    if one[i] == x :
        o = i
print(z,o)








