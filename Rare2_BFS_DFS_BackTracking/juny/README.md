# DFS, BFS, Backtracking
    written by "juny9610"


### DFS
    Stack 혹은 재귀함수로 구현
`Depth-First Search`, 즉 깊이우선탐색이다.  
현재 point에서 갈 수 있는 점들까지 들어가면서 탐색한다.

### BFS
    Queue를 사용해서 구현
`Breadth-First Search`, 즉 너비우선탐색이다.
현재 point에 연결된 가까운 point들부터 탐색한다.  
가중치가 없는 최단 경로는 무조건 BFS이다. 특정 칸에 처음 도달했을 때 까지의 경로의 길이가 다른 경로를 통해 도달한 길이보다 짧다는 보장이 전혀 없기 때문이다.


### 예제 (BOJ)
##### 1260번 DBF와 BFS
