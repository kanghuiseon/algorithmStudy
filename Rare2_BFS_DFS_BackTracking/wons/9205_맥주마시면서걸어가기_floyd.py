import sys

read = sys.stdin.readline

def floyd() :
    for k in range(len(node)) :
        for i in range(len(node)) :
            for j in range(len(node)) :
                if adjs[i][k] + adjs[k][j] < adjs[i][j] :
                    adjs[i][j] = adjs[i][k] + adjs[k][j]

T = int(read())
for _ in range(T) :
    N = int(read())
    node = [list(map(int,read().split())) for _ in range(N+2)]
    adjs = [[int(1e9)] * (N+2) for _ in range(N+2)]
    for i in range(N+2) :
        for j in range(N+2) :
            if i == j : adjs[i][j] = 0
            if abs(node[i][0]-node[j][0]) + abs(node[i][1]-node[j][1]) <= 1000 :
                adjs[i][j] = 1
                adjs[j][i] = 1

    floyd()

    if adjs[0][-1] == int(1e9) :
        print("sad")
    else :
        print("happy")
