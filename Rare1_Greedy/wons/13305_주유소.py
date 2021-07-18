import sys

read = sys.stdin.readline

N = int(read())
city = list(map(int,read().split()))
price = list(map(int,read().split()))

ans = price[0]*city[0]
idx = 0
for i in range(1,len(city)) :
    if price[i] < price[idx] :
        idx = i
    
    ans += (price[idx]*city[i])

print(ans)