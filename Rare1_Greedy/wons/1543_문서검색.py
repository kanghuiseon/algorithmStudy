

doc = input()
word = input()
ans = 0
for i in range(len(doc)) :

    j = i
    cnt = 0
    while True :
        if j + len(word) > len(doc) : break

        if doc[j:j+len(word)] == word :
            cnt += 1
            j += len(word)
        else :
            j += 1
    ans = max(cnt,ans)

print(ans)