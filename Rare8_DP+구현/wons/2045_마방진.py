import sys 

read = sys.stdin.readline

def findSum() :
    for i in range(3) :
        if board[i][0] and board[i][1] and board[i][2] : return sum([board[i][0],board[i][1],board[i][2]])
        if board[0][i] and board[1][i] and board[2][i] : return sum([board[0][i],board[1][i],board[2][i]])
        
    if board[0][0] and board[1][1] and board[2][2] : return sum([board[0][0],board[1][1],board[2][2]])
    if board[0][2] and board[1][1] and board[2][0] : return sum([board[0][2],board[1][1],board[2][0]])

    return (sum(board[0])+sum(board[1])+sum(board[2])) // 2

board = [list(map(int,read().split())) for _ in range(3)]
S = findSum()

for _ in range(3) :
    for i in range(3) :
        for j in range(3) :
            if not board[i][j] :
                if ((board[i][0] == 0) + (board[i][1] == 0) + (board[i][2] == 0)) == 1 :  
                    board[i][j] = S - (board[i][0] + board[i][1] + board[i][2])                    
                elif ((board[0][j] == 0) + (board[1][j] == 0) + (board[2][j] == 0)) == 1 :  
                    board[i][j] = S - (board[0][j] + board[1][j] + board[2][j])
                    
for row in board :
    print(*row)



