# 5주차. 트리, 최소 스패닝 트리, 유니온 파인드
## 1197. 최소 스패닝 트리 (골드 4)
크루스칼 알고리즘 완젼 기본 문제! (프림으로 풀어도 됨)

### 구현
우선 벡터를 vector<pair<int, pair<int, int>>> arr로 구현해서, 맨 앞에 int값을 간선크기로 정한다. 

그리고 sort를 해서 간선 크기가 작은 순서대로 정렬을 한다.

(sort의 시간복잡도는 O(nlogn) 임, 퀵소트로 정렬한다.)

그리고 나서 자기 자신을 부모로 설정해놓는다. (유니온-파인드 때문에)

그리고 arr앞에서부터 보면서 (최소 간선부터 보면서), 부모가 같지 않으면(checkParents 함수) 부모를 같게 만들고 해당 간선의 크기를 sum에 더한다.


### 유니온 파인드
```cpp
int find(int x){
    if(parents[x] == x)
        return x;
    else
        return parents[x] = find(parents[x]);
}

void union_find(int x, int y){
    int xp = find(x);
    int yp = find(y);
    if(xp != yp)
        parents[yp] = xp;
}

bool checkParents(int x, int y){
    int xp = find(x);
    int yp = find(y);
    if(xp == yp){
        return true;
    }
    return false;
}
```
- find : 일단 파라미터로 들어온 x값의 부모가 자신과 같으면 그냥 x리턴하고 그렇지 않으면 다시 find함수를 들어가서 x의 부모의 부모를 알아본다. (부모의 부모의 부모도 될 수 있음)
- union : x의 부모, y의 부모를 구하고, 만약 부모가 같지 않으면 yp의 부모를 xp로 설정한다.
- checkParent : x의 부모와 y의 부모가 같으면 true를 리턴하고, 그렇지 않으면 false를 리턴한다.


## 1774. 우주신과의 교감 (골드 4)
이것도 크루스칼로 품!

### 구현
n개의 우주신들의 좌표를 arr 변수에 넣고, 각 좌표 사이의 거리를 구한다.
```cpp
for(int i=0; i<arr.size(); i++){
    for(int j=i+1; j<arr.size(); j++){
        double distance = hypot(arr[i].first-arr[j].first, arr[i].second-arr[j].second);
        spaceDistance.push_back(make_pair(distance, make_pair(i+1, j+1)));
    }
}
```
거리는 일반 거리를 구하는 공식을 이용하고, hypot 함수를 이용한다. 
> hypot : 두 수의 각 제곱의 합의 제곱근  

그리고 spaceDistance라는 벡터(vector<pair<**double**, pair<**int**, **int**>>> spaceDistance;)의 첫번째 값으로 넣는다.

이 다음부터는 기본 크루스칼 알고리즘을 이용해서 sum을 구한다.

소수 둘째점에서 반올림을 하기 위해서 다음과 같이 한다.
```cpp
cout << fixed;
cout.precision(2);
cout << sum << endl;
```


## 1068. 트리 (골드 5)
### 구현
checkRoot함수로 해당 노드의 루트가 지워야할 루트거나, 현재 인덱스가 지워야할 루트라면 parents[i] = -2 를 저장한다.

그리고나서 다시 for문으로 현재 노드의 자식 개수를 세고 (checkLeaf) 마지막에 leafs 배열의 값이 0이면 (자식이 없으면) 리프노드의 갯수 ++ 을 해준다.

### checkRoot
```cpp
bool checkRoot(int x){
    if(x == removedN){
        return true;
    }
    else if(x == parents[x]){
        return false;
    }
    else if(x == -2){
        return true;
    }
    return checkRoot(parents[x]);
}
```

### checkLeaf
```cpp
bool checkLeaf(int x){
    if(parents[x] == x){
        return false;
    }
    else if(parents[x] != -2){
        return leafs[parents[x]] += checkLeaf(parents[x]) + 1;
    }
    else{
        leafs[x] = -2;
        return false;
    }
}
```

## 5052. 전화번호 목록 (골드 4)
### 정렬
첨에는 트리로 어떻게 풀어야 할 지 몰라서 정렬로 풀었다.

string으로 입력값을 받아서 벡터에 넣어서 sort한다.

그리고 나서 현재 인덱스의 값이 바로 다음 인덱스의 값의 접두사가 아니면 바로 넘어간다. 

(왜 바로 다음꺼만 보냐면 접두어가 같다면 정렬됐을때 바로 다음에 있기 때문에)

하지만 이번주는 트리기 때문에 트리로 풀어야한당…

### 트리


## 14621. 나만 안되는 연애 (골드 3)
이것도 기본 최소 스패닝 트리 문제에 성별만 비교하고 모든 노드가 연결되어있는지만 체크했다.

최소 스패닝 트리는 크루스칼 알고리즘을 사용했다.

### 틀렸습니다.
처음에는 두 노드에 크기가 다른 엣지가 연결될 수도 있다는 생각에 엣지를 key값으로 가지는 Map을 만들어서 해당 엣지가 map에 포함되어있으면 if문으로 안들어가게 짰는데, 생각해보니 union을 할때 어차피 루트가 동일하게 설정이 되기 때문에 한번 연결되면 다음에 볼 필요가 없다는 생각을 못했다.

아직 생각이 짧다!! 문제를 많이 풀어봐야겠다.

그리고 문제를 잘 읽자!!!! 제발!!!!

그래프가 안만들어지면 -1을 출력해야 한다고 분명 문제에 적혀 있는데 그냥 sum만 출력했다

이런!


## 1717. 집합의 표현 (골드 4)
기본적인 유니온 파인드 문제!

만약 같은 집합에 속해 있다면 같은 root를 가지고 있기 때문에 YES를 출력할 것이고 다른 집합에 있다면 다른 root를 가지고 있기 때문에 NO를 출력할 것이다! 끝!


## 1944. 복제 로봇 (골드 2)
### 구현
Bfs + 크루스칼 알고리즘 문제임
시작 로봇의 위치와 키들의 위치를 한 벡터(copies)에 다 넣고 각각에 대해서 거리를 계산했다. 

거리를 계산할때 bfs를 사용했다. 

현재 위치에서 타겟 위치까지 갈때 최소로 몇칸을 이동하는지를 봐야하기 때문에 bfs를 사용했다. 해당 함수는 몇칸 이동했는지를 리턴한다.

```cpp
if(cx == target.first && cy == target.second){
            return d;
        }
```
만약 위의 조건식에서 안끝나고 while문이 끝났다면 -1을 리턴해줬는데 이어지는 경우가 없다는 말이므로 바로 -1를 출력하고 리턴했다.

이렇게 계산한 거리를 distance 변수에 저장하고, mst라는 pair<int, pair<int, int>> 형 변수를 만들었다.

이 변수의 second는 copies 배열의 인덱스 값을 의미한다. 
예) copies : (0,0), (1,0), (3,3) -> mst : (0,1), (0,2), (1,2) 

이렇게 각각의 노드 위치에 대한 인덱스 값이 저장됨.

그리고 크루스칼을 위해서 각 노드의 parents를 자기 자신으로 설정하고 만약 다른 트리에 존재한다면 합치고 distance값을 더해준다.

최종적으로 더한 값을 출력한다.


### 메모리 초과
queue push하고나서 check배열에 check 안해줘서


### 틀렸습니다 
distance계산을 하고나서 연결이 실패해서 -1을 리턴하는 경우에는 -1를 출력하고 바로 끝냈어야 했는데, 이 부분에 대한 코드를 넣어주지 않았다.

넣어줘도 틀렸습니다가 나왔었는데 크루스칼 코드에서 엣지 갯수를 세서 이게 노드-1 개이면 sum을 출력하고 그렇지 않으면 -1을 출력하도록 하는 코드를 제거하지 않아서 틀렸다. 

심지어 노드-1개가 아니라 전체 엣지-1을 했음….화이자 주사 맞고 정신이 없었나봄




## 1976. 여행 가자 (골드 4)
유니온 파인드 문제!

```cpp
for(i=0; i<m-1; i++){
        if(!checkSameArea(cities[i], cities[i+1])){
            break;
        }
}
```
만약에 root가 같다면 현재 위치에서 갈 수 있다는 말이다.

그래서 동혁이의 여행 계획에 속한 도시들이 모두 같은 root를 가지고 있다면 모두 갈 수 있다는 말이니까 YES를 출력한다.

## 20040. 사이클 게임 (골드 4)
이것도 기본적인 유니온 파인드 문제!

만약 같은 Root를 가지고 있다면 사이클이 생겼다는 말이니까 몇번째인지 출력하고 끝낸다!

```cpp
int cnt = 0;
for(int i=0; i<arr.size(); i++){
    int a = arr[i].first;
    int b = arr[i].second;
    if(!checkSameArea(a, b)){
        union_find(a, b);
        cnt++;
    }else{
        printf("%d\n", cnt+1);
        return 0;
    }
}
```

## 2263. 트리의 순회 (골드 3)
### 구현
구현 순서는 다음과 같다!
1. 포스트오더에서 가장 마지막이 루트니까 루트를 먼저 찾는다.
2. 인오더에서 해당 루트를 기준으로 양쪽으로 가르면 왼쪽 트리, 오른쪽 트리가 된다.
3. 포스트오더에서 위의 정보를 가지고 다시 왼쪽 트리의 루트부터 찾는다.
4. 왼쪽을 다 보고 나면 재귀에서 빠져 나와서 오른쪽을 보는 재귀로 들어간다.

함수 들어갈때 인오더와 포스트오더의 각각의 인덱스를 찾는게 좀 어려웠다….
```cpp
void findPreOrder(int is, int ie, int ps, int pe){
    if(is > ie || ps > pe)
        return;
    cout << postorder[pe] << ' ';
    findPreOrder(is, inOrder[postorder[pe]]-1, ps, ps+inOrder[postorder[pe]]-is-1);
    findPreOrder(inOrder[postorder[pe]]+1, ie, ps+inOrder[postorder[pe]]-is, pe-1);
}
```


## 4195. 친구 네트워크 (골드 2)
### 구현
Map<string, int> mm, map을 만들어서, 각 이름에 대한 노드 번호를 만들어 준다.

그리고 각 이름에 대해서 union_find를 진행하는데 여기서 중요한게 현재 노드가 가지고 있는 leaf의 수도 같이 관리를 해야 한다는 것이다.

각각의 root를 찾고 만약 root가 다르다면, parents[y] = x;를 해주고 함께 leafs[x] += leafs[y] 해줘서 y의 leaf의 개수를 x에 더해준다.

합치고 나서 해당 root의 leaf개수를 출력하면 된다.


### 런타임 에러
친구 관계의 수가 100000이고 친구의 수는 그 이상인데 그걸 생각못했다ㅠㅠ



## 2250. 트리의 높이와 너비 (골드 2)
어떻게 풀라는건지 도저히 모르겠다!












