# 3주차. 다익스트라, 벨만-포드, 플로이드 와샬 알고리즘
## 다익스트라 
최단 경로를 구하는 알고리즘 (Shortest Path)

하나의 정점에서 다른 모든 정점으로 가는 최단 거리를 구할 때 사용한다.

하지만 음의 간선이 있는 경우에는 사용할 수 없고, 양의 간선이 있는 경우에만 사용이 가능하다.

### priority queue (Min heap)
다익스트라를 구현할 때는 가장 짧은 거리의 노드부터 봐야하므로, priority queue를 사용해서 (거리, 노드) 순으로 뽑는다.
```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
```
위와 같이 greater를 이용해서 기존의 Max heap이었던 pq를 Min heap으로 바꿔서, 가장 짧은 거리의 노드 먼저 볼 수 있도록 한다.

### 시간 복잡도
다익스트라의 시간복잡도는 인접 행렬로 풀었을 경우에는 O(V*V)이다.

이 경우에, 만약 N의 크기가 큰 경우에는 시간 초과가 날 수 있다.

그래서 보통은 인접 리스트를 사용해서, 자기 자신과 연결된 노드만 볼 수 있도록 한다.

인접 리스트를 사용하게 되면, O(V*logV) 이다.

### 거리 계산
거리를 계산할 때는, 보통 distance를 나타내는 일차원 배열을 하나 만들고,

시작점을 0으로 지정하고, 나머지 지점들은 MAX값으로 설정한다. (최소값을 구하는 것이기 때문에 각 노드는 처음에 MAX값을 가져야 한다.)

distance 배열의 값들이 의미하는 것은, 해당 노드로 도착할때까지의 최단 거리이다.


그리고 현재 시작 노드와 연결 되어있는 노드를 하나씩 보면서, 만약 
```cpp
for(int i=0; i<arr[node].size(); i++){
    int nextNode = arr[node][i].first;
    int nextDist = dist + arr[node][i].second
    if(distance[nextNode] > nextDist){
        pq.push(make_pair(nextDist, nextNode));
}
```
만약 현재 노드까지의 거리와, 현재 노드에서 다음 노드로 가는 거리의 합이 distance배열의 값보다 작으면, 위의 값은 다음노드까지의 최단 거리를 의미하므로 배열 업데이트를 해준다.

pq의 값이 빌때까지 진행을 하고나서 distance 값을 보자.

만약 목적지에 도착할 수 없다면, 해당 목적지의 distance값이 MAX로 설정 되어있을 것이고, 갈 수 있다면, MAX가 아닌 값이 들어갈 것이다.


***

## 벨만 포드
 다익스트라와 동일하게 최단 거리를 구하는 알고리즘이지만, 한가지 다른 점은 다익스트라와 달리 벨만 포드는 음수 간선이 있는 경우에도 최단 거리를 구할 수 있다는 점이다.

### 시간복잡도
벨만 포드의 시간복잡도는 V-1번 모든 간선을 검사하기 때문에 O(VE)이다.

(실행속도가 다익스트라보다 느려서 음수간선이 없을때는 굳이..? 사용하지 않는다.)

**왜 V-1번 돌리면 다 확인한거라고 생각해야하나?** 

**왜 V-1 번이 최대 업데이트가 가능한 횟수일까?**

최악의 경우를 생각해보자.

만약 노드 1번부터 노드 V번까지 일자로 가능 경로가 있다고 한다면,
1번 노드부터 V번 노드까지가는 경로의 수는 V-1이다. 

그래서 V-1번까지만 돌리고 V번째 돌렸을때까지 업데이트가 발생한다면 음의 사이클이 생겼구나..!라고 생각하는 것이다.

벨만포드도 인접 리스트로 구현해서 시간을 줄일 수 있다.

### 구현
벨만 포드도 다익스트라와 마찬가지로 한 노드에서부터 시작한다.

하지만, 짧은 거리인 경우만 보는 다익스트라와는 달리 모든 노드를 확인하며, 각 노드에 대한 엣지를 다 확인한다.

이 과정을 V-1번 확인하면서 distance배열을 업데이트한다. (사실 V-1번 확인하든 V번 확인하든 , V+1번 확인하든 답은 똑같다.)

여기서, 음수 사이클이 존재할 수 있는데, 이 경우에는 위의 과정이 끝난 후, 한번 더 노드 전체를 확인하면서, 만약 또 값의 업데이트가 생긴다면, 음의 사이클이 있다고 생각하고, 바로 빠져나오도록 한다.

```cpp
for(int i=1; i<=n-1; i++){
    for(int node=1; node<n+1; node++){
        for(int j=0; j<arr[node].size(); j++){
            if(distance[node] == MAX)
                continue;
            if(distance[node] + arr[node][j].second < distance[arr[node][j].first]){
                    distance[arr[node][j].first] = distance[node] + arr[node][j].second;
          }
        }
    }
}
bool flag = true;
for(int node=1; node<n+1; node++){
        for(int j=0; j<arr[node].size(); j++){
            if(distance[node] == MAX)
                continue;
            if(distance[node] + arr[node][j].second < distance[arr[node][j].first]){
                flag = false;
          }
        }
    }

if(!flag){
    printf("음수간선 존재");
}
```

***

## 플로이드 와샬
**모든 정점** 에서 **모든 정점** 까지 가는 경로를 구하고 싶을 때 사용한다.
 
### 차이점
다른 최단 거리 알고리즘과 다른 점은 한 노드에서 다른 노드로 바로 가는 것이 아니라, 중간에 거쳐가는 노드도 포함해서 생각을 해야 한다는 것이다.
(바로 가는 거리보다, 거쳐가는 거리가 더 짧은 경우가 있을 수도 있음.!)

### 시간 복잡도
V만큼 3중 for문으로 구현했기 때문에 O(V^3) 이다.

### 구현
모든 정점에 대한 것이므로 distance배열은 이중 배열로 만든다.
![0]()

![1]()

위의 그림과 같이 바로 가는 거리에 대해서 먼저 초기화를 해주고, 그렇지 않은 부분은 MAX값으로 초기화 한다.

값을 업데이트 할 때에는,

노드 1을 거쳐가는 경우, 노드 2를 거쳐가는 경우….순서대로 보면서,

**X에서 Y로 가는 최소비용 vs X에서 노드K로 가는 비용 + 노드K에서 Y로 가는 비용**
을 비교하면서 distance배열에 더 작은 값을 입력한다.

코드로 보면
```cpp
for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(distance[i][j] > distance[i][k] + distance[k][j]){
                distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }
}
```
가장 바깥쪽의 k가 거쳐가는 노드이고, distance[I][j]값과 distance[i][k] + distance[k][j] 값을 비교하도록 한다.














