# 9주차. 아무거나
## 1655. 가운데를 말해요 (골드 2)
### 시간초과 코드
```cpp
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
        sort(v.begin(), v.end());
        int middle;
        if(v.size()%2 == 0){
            middle = v.size()/2-1;
        }else{
            middle = v.size()/2;
        }
        printf("%d\n", v[middle]);
    }
    return 0;
}
```
값을 넣을때마다 벡터를 정렬해주면 N^2logN이 되어서 시간초과가 난다.


### 정답 코드
```cpp
priority_queue<int, vector<int>, greater<int>> minH;
priority_queue<int> maxH;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        if(maxH.empty())
            maxH.push(a);
        else if(minH.size() < maxH.size())
            minH.push(a);
        else
            maxH.push(a);
        
        if(!maxH.empty() && !minH.empty() && maxH.top() > minH.top()){
            int a = maxH.top(); maxH.pop();
            int b = minH.top(); minH.pop();
            maxH.push(b); minH.push(a);
        }
        printf("%d\n", maxH.top());
    }
    return 0;
}
```
아무리 생각해도 시간을 줄일 수 있는 방법을 모르겠어서 다른 사람의 코드를 참고했다.

1. 값들을 반으로 나눠서 작은 부분을 최대 힙에 넣고 큰 부분을 최소 힙에 넣는다.
2. 최대 힙의 크기가 최소 힙의 크기보다 1보다 크거나 같도록 유지한다. (맨 첨에 값을 넣을 때 무조건 최대 힙에 먼저 넣는다.)
3. 값을 넣고 나서 최대 힙과 최소 힙의 top값을 비교해서 최대 힙의 top 값이 최소 힙의 top보다 크면 최소 힙의 top갑과 swap한다.
4. 이렇게 하면 최대 힙의 top에는 중간값이 들어가게 된다.

값들의 수가 짝수인 경우에는 두 힙의 사이즈가 같아야 하고, 홀수인 경우에는 최대 힙의 사이즈가 최소 힙의 사이즈보다 1 커야 한다. 



## 16234. 인구 이동 (골드 5)
bfs문제!

### 구현
처음에 bfs로 현재 깰 수 있는 장벽의 개수를 구하고

장벽을 깼을 때의 나라 개수와 인구 합을 구하여 합/개수의 값을 연합한 나라의 인구수로 바꿔준다.

그리고 나서 answer++를 해준다.

만약 더 이상 깰 장벽이 없다면 더 이상의 인구 이동이 일어나지 않는다는 의미이므로 break를 하고 답을 출력한다.

## 9935. 문자열 폭발 (골드 4)
### 시간 초과 코드
```cpp
while(true){
    v.clear();
    int cnt=0;
    for(int i=0; i<s1.size();){
        if(s1[i] == s2[0]){
            int j;
            for(j=0; j<s2.size(); j++){
                if(s1[i+j] != s2[j])
                    break;
            }
            if(j == s2.size()){
                s1.erase(i, s2.size());
                cnt++;
            }else{
                v.push_back(s1[i]);
                i++;
            }
        }else{
            v.push_back(s1[i]);
            i++;
        }
    }
    if(cnt == 0){
        break;
    }
}
```
while(true) 때문에 1,000,000 * 36 * … 돼서 시간 초과가 난 것 같다.


### 정답 코드
```cpp
for(int i=0; i<s1.size(); i++){
    v.push_back(s1[i]);
    if(v[v.size()-1] == s2[bombSize-1]){
        bool flag = true;
        for(int j=2; j<=bombSize; j++){
            if(v[v.size()-j] != s2[bombSize-j]){
                flag = false;
            }
        }
        if(flag){
            v.erase(v.end()-bombSize, v.end());
        }
    }
}
```
폭발 문자열의 마지막 문자가 벡터의 마지막 값이랑 같다면 벡터의 마지막부터 폭발 문자열길이만큼의 문자를 본다.

만약 맞다면 벡터의 마지막부터 그 길이만큼 erase 해준다.


## 텀 프로젝트 (골드 3)
### 시간 초과 코드
```cpp
int check(int start, int current){
    if(start == current && visit[current] == 1){
        return 1;
    }
    if(visit[current] == 1 || visit[current] == -1){
        return 0;
    }
    
    visit[current] = 1;
    if(!check(start, arr[current])){
        visit[current] = 0;
    }
    return visit[current];
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        int answer = 0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        memset(visit, 0, sizeof(visit));
        for(int i=1; i<=n; i++){
            if(visit[i] == 0){
                visit[i] = 1;
                if(!check(i, arr[i])){
                    visit[i] = -1;
                }
            }
        }
        for(int i=1; i<=n; i++){
            if(visit[i] == -1){
                answer++;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
```

### 반례
```cpp
Input
1
3
2 3 2
```
1->2->3->2 에서 2->3->2의 사이클을 확인했다면 사이클 체크를 해줘야 하는데 

위의 코드에서는 따로 체크하지 않고 1에만 -1값을 넣어줬다. 

### 정답 코드
```cpp
void dfs(int start){
    visit[start] = true;
    int next = arr[start];
    if(!visit[next]){
        dfs(next);
    }else if(!cycleCheck[next]){
        for(int i=next; i !=start; i=arr[i])
            cnt++;
        cnt++;
    }
    cycleCheck[start] = true;
}
```
시간 초과를 도저히 못잡겠어서 다른 사람의 코드를 참고해서 풀었다.


## 16235. 나무 재테크 (골드 4)
### 구현
봄, 여름, 가을, 겨울에 하는 이들을 각각 함수로 만들고 k년이 지날때마다 한번씩 실행했다.

그리고 나서 마지막에 살아남은 나무의 수를 셌다.
### 봄
```cpp
void spring(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!tree[i][j].empty()){
                sort(tree[i][j].begin(), tree[i][j].end());
                vector<int> newTree;
                for(int k=0; k<tree[i][j].size(); k++){
                    if(food[i][j] - tree[i][j][k] >= 0){
                        food[i][j] -= tree[i][j][k];
                        newTree.push_back(tree[i][j][k]+1);
                    }else{
                        deadTree[i][j].push_back(tree[i][j][k]);
                    }
                }
                tree[i][j] = newTree;
            }
        }
    }
}
```
나이만큼 양분을 섭취하고 나이를 1 증가시킨다. (어린 순으로 섭취하기 때문에 sort를 해준다.)

양분을 섭취못하면 바로 die하도록 한다.
### 여름
```cpp
void summer(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!deadTree[i][j].empty()){
                for(int k=0; k<deadTree[i][j].size(); k++){
                    food[i][j] += deadTree[i][j][k]/2;
                }
            }
        }
    }
}
```
죽은 나무를 가지고 나이/2의 값을 양분에 더해준다.

### 가을
```cpp
void fall(){
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!tree[i][j].empty()){
                for(int k=0; k<tree[i][j].size(); k++){
                    if(tree[i][j][k] % 5 == 0){
                        for(int l=0; l<8; l++){
                            int nx = i + dx[l];
                            int ny = j + dy[l];
                            if(nx < 1 || nx > n || ny < 1 || ny > n)
                                continue;
                            tree[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}
```
번식하는 나무의 나이가 5의 배수이면 인접한 8개의 칸에 나이가 1인 나무를 추가해준다.


### 겨울
```cpp
void winter(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            food[i][j] += s2d2[i][j];
        }
    }
}
```
s2d2가 땅에 양분을 추가해준다.


## 1107. 리모컨 (골드 5)


















