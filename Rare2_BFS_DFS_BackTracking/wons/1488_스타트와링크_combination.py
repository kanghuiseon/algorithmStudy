
import sys
from itertools import combinations

read = sys.stdin.readline

def solve():
    res = int(1e9)
    num = [i for i in range(N)]
    for candi in combinations(num,N//2):
        t1 = list(candi)
        t2 = list(set(num)-set(candi))

        t1_s = 0
        for x,y in combinations(t1,2):
            t1_s += (mat[x][y] + mat[y][x])
        t2_s = 0
        for x,y in combinations(t2,2):
            t2_s += (mat[x][y] + mat[y][x])

        if res > abs(t1_s - t2_s):
            res = abs(t1_s - t2_s)

    return res

N = int(read())
mat = [list(map(int,read().split())) for _ in range(N)]


print(solve())
