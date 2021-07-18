import sys

read = sys.stdin.readline

N = int(read())
man = list(map(int,read().split()))
woman = list(map(int,read().split()))

manU,manD = [],[]
for m in man : 
    if m < 0 : manD.append(abs(m))
    else : manU.append(abs(m))

womanU,womanD = [],[]
for w in woman :
    if w < 0 : womanD.append(abs(w))
    else : womanU.append(abs(w))

manU.sort(); womanD.sort()
U,D = 0,0
ans = 0
while True :
    if U >= len(manU) or D >= len(womanD) : break

    if manU[U] < womanD[D] :
        ans, U, D = ans+1, U+1, D+1
    else :
        D += 1

manD.sort(); womanU.sort()
U,D = 0,0
while True :
    if D >= len(manD) or U >= len(womanU) : break

    if womanU[U] < manD[D] :
        ans, U, D = ans+1, U+1, D+1
    else :
        D += 1

print(ans)