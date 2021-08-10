import sys

read = sys.stdin.readline

T = int(read())
for _ in range(T) :
    K,N = map(int,read().split())

    stu = [list(map(int,read().split())) for _ in range(4)]
    c1,c2 = [],[]
    for i in range(N) :
        for j in range(N) :
            c1.append(stu[0][i] + stu[1][j])
            c2.append(stu[2][i] + stu[3][j])

    c1.sort(); c2.sort()

    cmp = int(1e9)
    res = 0
    for c in c1 :
        weight = K - c

        left = 0; right = len(c1)-1
        while left <= right :
            mid = (left+right)//2

            if cmp == abs(weight - c2[mid]) and res > c + c2[mid]:
                res = c+c2[mid]
            
            elif cmp > abs(weight - c2[mid]) :
                cmp = abs(weight - c2[mid])
                res = c + c2[mid]
            
            if weight > c2[mid] :
                left = mid + 1
            else :
                right = mid - 1
    print(res)

    



