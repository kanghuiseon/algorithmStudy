import sys

read = sys.stdin.readline


def insert(word):
    trie = Trie
    for c in word:
        if c not in trie:
            trie[c] = {}
        trie = trie[c]
    trie['*'] = True
 
def search(word) :
    trie = Trie
    for c in word:
        if c not in trie:
            return False
        trie = trie[c]
    return '*' in trie and len(trie) == 1

T = int(read())
for _ in range(T) :
    N = int(read())
    Trie = {}
    call = []
    for _ in range(N) :
        c = read().strip()
        insert(c)
        call.append(c)
    
    call.sort(key=lambda x : len(x))
    isConsistent = True
    for c in call :
        if not search(c) :
            isConsistent = False
            break
    
    if isConsistent :
        print("YES")
    else :
        print("NO")
    

    
