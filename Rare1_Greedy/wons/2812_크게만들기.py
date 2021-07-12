

K = 2 
num = "zbgaj"

stack = []

for n in num :
    while K and stack and stack[-1] < n :
        stack.pop()
        K -= 1
    stack.append(n)

while K :
    stack.pop()
    K -= 1

print(("".join(stack)))