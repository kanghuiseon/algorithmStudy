import sys

read = sys.stdin.readline

R,C,M = map(int,read().split())
board = [[0] * (C+1) for _ in range(R+1)]
shark = []
for _ in range(M) :
    r,c,s,d,z = map(int,read().split())
    shark.append([r,c,s,d,z])
    board[r][c] = z

ans = 0
for c in range(1,C+1) :
 
    idx,rx = 0,R+1
    for i in range(len(shark)) :
        if shark[i][1] == c and shark[i][0] < rx :
            idx = i
            rx = shark[i][0]
    if rx != R+1 :
        ans += shark[idx][4]
        board[shark[idx][0]][shark[idx][1]] = 0
        shark.pop(idx)

    after = []
    for i in range(len(shark)) :
        cr,cc,cs,cd,cz = shark[i]

        nr,nc,s = cr,cc,cs
        if cd == 1 or cd == 2 :
            s = s % ((R-1)*2) if s > ((R-1)*2) else s
            while s :
                if cd == 1 and nr == 1 : cd = 2
                if cd == 2 and nr == R : cd = 1
                    
                nr = nr - 1 if cd == 1 else nr + 1
                s -= 1
        else :
            s = s % ((C-1)*2) if s > ((C-1)*2) else s
            while s :
                if cd == 3 and nc == C : cd = 4
                if cd == 4 and nc == 1 : cd = 3
                    
                nc = nc - 1 if cd == 4 else nc + 1
                s -= 1
        after.append([nr,nc,cs,cd,cz])
        
    board = [[0] * (C+1) for _ in range(R+1)]
    shark = []
    after.sort(key=lambda x : -x[4])
    for i in range(len(after)) :
        if board[after[i][0]][after[i][1]] < after[i][4] :
            board[after[i][0]][after[i][1]] = after[i][4]
            shark.append(after[i])
  
print(ans)
