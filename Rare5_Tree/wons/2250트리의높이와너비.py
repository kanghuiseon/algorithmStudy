import sys

read = sys.stdin.readline

N = int(read())
tree = {}
for _ in range(N) :
    root,left,right = map(int,read().split())

    tree[root] = [left,right]

print(tree)