# 2주차. BFS, DFS, 백트래킹
## 1260. DFS와 BFS (실버 2).  
memset 함수를 사용할 때는  #include cstring 필수로 추가해주기.!


## 10026. 적록 색약 (골드 5).  
bfs로 품.  
적록 색약이 아닌 경우에는 기본적인 bfs 방법으로 풀고, 
적록 색약인 사람은 arr에서 ‘G’ 를 ‘R’로 바꾸고 bfs로 품.

중간에 check배열 초기화 해주기. 

## 1987. 알파벳 (골드 4).  
**시간 초과 코드**
**왜 시간 초과가 날까!** - 해당 알파벳이 존재하는지를 보기 위해서 이때까지 나온 알파벳을 string에 더했는데, 이게 오래걸리고 (n번 돈다), 또 checkChar에서 n번보고 해서 시간 초과가 난거 같다. **(정확하게는 잘 모르겠음ㅠ)**

이미 방문한 알파벳인지 확인하기 위해서, alpha 배열을 하나 만들고 arr[nx][ny]-‘A’ 해줘서 숫자로 만들고 배열에 넣음, 이렇게 해서 방문했는지 안했는지를 체크함.


## 2206. 벽부수고이동하기 (골드 4).  
처음에는 하나의 check 배열을 가지고 문제를 품

하지만 여기엔 문제가 있음…! 두둥

예를 들어 벽을 한번 뿌시고 온 애가 들렀다 가서 큐에 집어넣었을 경우가 있다고 해보자굿. 그럼 체크배열에도 체크를 하겠지?

근데 벽을 한번도 안뿌신 애가 방금 거기에 들어갈려고 하면 이미 체크를 했기 때문에 들어갈 수 없게 되는 상황이 발생하는 것이다…! 두둥 클로즈업

그래서 3중 배열을 만들어서, 벽을 뿌셨을 경우와, 벽을 뿌시지 않았을 경우를 따로 체크하도록 하기로 했다고 한다.

## 14889. 스타트와 링크 (실버 3).  
코드는 permutation짜는 코드를 기반으로 짬.

N/2개씩의 순열을 만들어서 (dfs), 만든 순열에 대해서는 check배열에서 true를 저장.

만약 현재 순열의 개수가 n/2이면 각 점수를 계산한다.

스타트팀, 링크 팀 구별은 check배열을 만들어서 true이면 스타트팀, false이면 링크팀 이런식으로 작성.

## 9663. N-Queen (골드 5).  
일차원 배열로 확인, 인덱스는 2차원배열에서의 열을 의미하고, 값은 2차원 배열에서의 행을 의미.

idx(세로줄)을 기준으로 내 앞에 있는 줄들과 행이 같거나, 대각선이 같은 경우에는 그냥 break해줘서 더이상 함수를 들어가지 않도록 함.

만약 그런 경우가 없다면 다음 열로 dfs 진행.


## 9205. 맥주 마시면서 걸어가기 (실버 1).  
bfs로 풀었당

편의점위치랑 목적지 위치를 한 벡터(com)에 때려박고

check배열을 만들어서 조건이 맞으면 com[i]의 위치에 방문했으므로, check[i]를 true로 만들어줬다.

여기서 조건은 맨해튼 거리 즉, 현재 위치와 com[i]의 위치의 abs(x의 차이 + y차이)의 크기가 1000보다 작거나 같으면 해당 위치에 맥주가 고갈되는일 없이 갈 수 있다는 말이므로 방문하고, queue에다가 넣어줬다.

그리고나서, queue에서 뺀 x, y값이 목적지의 위치와 같다면 “happy”를 출력하고, 그렇지 않으면 “sad”를 출력했다.

처음에 계속 틀린 이유가, check배열을 만들지 않고, com배열을 sort해서 할 수 있을 줄 알았는데, 이렇게 하면 x, y 동시에 솔팅이 불가능해서 원하는대로 코드가 구현되지 않았다. (멍청한 생각…, 또함)

그래서 check배열로, 현재 위치에 방문했는지 안했는지를 체크해주었다.


## 1707. 이분 그래프 (골드 4).  
이분 그래프란 노트에 색깔을 칠한다고 했을때, 나와 연결된 노드가 나랑 같은 색깔이면 안되는 그래프이다. (나랑 연결된 그래프는 무조건 나랑 다른 색이어야 함)

**틀렸습니다** - 연결리스트가 아닐수도있다는것을 간과함
**시간초과** - 이중벡터인데 arr처럼 사용해서 V^2이 됨……바본가……
**틀렸습니다** - 기존에는 string answer를 전역으로 선언해서, bfs에서 NO가 나오는 경우에는 answer를 NO로 바꿔주고 아니면 YES로 바꿔줌.

이 경우에는 만약 연결 리스트가 아닌 경우에 answer가 YES로 바뀔 가능성이 있음. 그래서 bfs함수의 리턴 타입을 bool로 바꾸고 NO가 나오면 바로 return false하도록 하고, bfs함수가 끝나도록 함.


## 9019. DSLR (골드 5).  
**시간초과** - L, S 연산에서 string으로 문제를 풀어서 시간초과가 난듯함

그런줄 알았는데 그냥 전체적으로 다 int형으로 풀었어야 함!


## 14442. 벽부수고 이동하기 2 (골드 3).  
벽 부수고 이동하기 1이랑 동일한 방식으로 품.

대신에 check배열을 [1003][1003][12] 로 선언해서, 한번도 안뿌셨으면 [x][y][0], 한번 뿌셧으면 [x][y][1], 두번 뿌셧으면 [x][y][2]… 이런 식으로 생각해서 품.

그리고 처음에 1%에서 시간 초과가 났는데, 이거는 arr[nx][ny] == 1 인 경우에, check배열 확인을 안해줘서 생긴 것 같음, check[nx][ny][wall+1] == 0 조건을 추가해주니 시간 초과는 없어졌음.

**런타임 에러(Segfault)** - 시간초과 나길래 string으로 받은거 인풋값은 int형으로 바꿔줬는데 정작 arr선언을 그냥 string인 채로 냅둬버림… 

**런타임 에러(Invalid Pointer)** - 배열 선언을 nxn으로 함…..nxm인데……

 
## 1600. 말이 되고픈 원숭이 (골드 4).  
일단 옮기기 위한 배열을 하나 더 만들어 주었다. (말이 갈 수 있는!)

그리고 나서, 벽부수고 이동하기와 동일한 방식으로 check배열을 만들었다.

check[][][0]은 안뛰어넘은거, check[][][1]은 한번 뛰어넘은거 등등

만약에 말처럼 뛸 수 있는 횟수가 k+1을 넘지 않았으면, 말처럼 뛴 후의 위치도 queue에 넣어주었다. 
(조건은, check[nx][ny][hurdle+1]이 아직 방문하지 않아야 하고, arr[nx][ny]가 장애물이면 안된다.) 
(처음에 이 조건을 추가하지 않았더니, 장애물인 곳에 안착을 해버려서 틀렸습니다가 나왔다. 조건 이해를 잘못함)

또한, 장애물을 뛰어넘을 수 있든 말든 인접한 곳에 대해서는 이동을 해야 하므로,

이 부분에 대해서는 arr[nx][ny] 가 1인 경우에는 (장애물이 있는) 이동하지 않고, 장애물이 없고, 방문하지 않은 곳이면 방문을 하고 queue에다가 넣어준다.

처음에 틀렸습니다가 나왔을때는 문제 이해를 잘못해서 몇번 방문했는지로 알아들어서 항상 1이 더해진 값이 나왔었다.

근데 문제를 다시 읽어보니 몇번 이동했냐여서 1을 뺀 값을 출력하도록 했다…

**결론 : 문제를 잘 읽고 풀자..!**


## 1937. 욕심쟁이 판다 (골드3).  
처음에는 그냥 dfs로 풀어서 시간초과가 남.

그담에는 메모이제이션 이용해서 현재 칸수는 현재칸까지 올 수 있는 것들의 수라고 생각하고 check배열을 꾸밈.

근데 반례를 찾아냄. 3 [1 2 3][6 5 4][7 8 9] 인 경우에는 내 생각대로 check배열은 채워졌는데, 정답이 아님.

그래서 다시 생각해서, 현재칸까지 올 수 있는 것들의 수가 아니라 현재칸에서 갈 수 있는 칸의 수를 현재칸에 넣기로 함.

그래서 품!

dp에 값이 들어가면 안바뀐다고 생각해야함… 이거 땜에 생각하는게 복잡했당…


## 2580. 스도쿠 (골드 4).  
뭐야!


## 12100. 2048 (Easy) (골드2).  
뭐야!


## 16946. 벽 부수고 이동하기 4 (골드 2).  
뭐얏!


## 17136. 색종이 붙이기 (골드 2).   
호호

## 2233. 사과나무 (골드1)
## 20927. Degree Bounded Minimum Spanning Tree (골드 1)




