N,K = map(int,input().split())
num = input()

stack = []

for n in num :
    while K and stack and int(stack[-1]) < int(n) :
        stack.pop()
        K -= 1
    stack.append(n)

while K :
    stack.pop()
    K -= 1

print(int("".join(stack)))