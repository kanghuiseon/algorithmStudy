import sys 
from collections import deque

read = sys.stdin.readline

def bfs(x,y) :
    q = deque()
    q.append([x,""]) # x , path
    visited = [0 for _ in range(10001)]

    while q :
        cur, path = q.popleft()
        if cur == y :
            return path

        if visited[cur] == 1 : continue
        visited[cur] = 1
        
        # D,S,L,R
        cmd = ["D","S","L","R"]
        case = [2*cur%10000, cur - 1 if cur != 0 else 9999, 
                int((cur%1000 * 10) + (cur//1000)),
                int((cur%10 * 1000) + (cur//10))]
        for i in range(4) :
            if visited[case[i]] == 0 :
                q.append([case[i],path+cmd[i]])
    

T = int(read())
for _ in range(T) :
    x,y = map(int,read().split())
    print(bfs(x,y))

