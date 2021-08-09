import sys
sys.setrecursionlimit(int(1e9))
read = sys.stdin.readline

def preorder(in_L,in_R,po_L,po_R) :

    if (in_L > in_R) or (po_L > po_R) : return

    root = postorder[po_R]

    L = inIdx[root] - in_L
    R = N - 1 - L

    print(root,end=' ')

    preorder(in_L,in_L+L-1,po_L,po_L+L-1)
    preorder(in_L+L+1,in_R,po_L+L,po_R-1)



N = int(read())
inorder = list(map(int,read().split()))
postorder = list(map(int,read().split()))
inIdx = [i for i in range(N+1)]
for i,in_ in enumerate(inorder) :
    inIdx[in_] = i

preorder(0,N-1,0,N-1)