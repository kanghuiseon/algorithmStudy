# 7주차. 다이나믹 프로그래밍
## 9251. LCS (골드 5)
학교에서 과제로 했었어서 쉽게 풀었다.

만약 s1의 알파벳과 s2의 알파벳이 같으면 대각선위의 값에 1을 더했고, 그렇지 않다면 위, 왼쪽의 값 중 max값으로 설정했다.
```cpp
for(int i=0; i<s1.size(); i++){
    for(int j=0; j<s2.size(); j++){
        if(s1[i] == s2[j]){
            dp[i+1][j+1] = dp[i][j] + 1;
        }
        else{
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
}
printf("%d\n", dp[s1.size()][s2.size()]);
```
 
## 9252. LCS 2 (골드 5)
LCS에서 방향 배열만 추가했다.

만약 대각선에서 왔으면 현재 위치에 3, 위에서 왔으면 1, 왼쪽에서 왔으면 2를 설정해주고,

dir[s1.size()][s2.size()] 부터 보면서 온방향으로 가되 만약 대각선에서 왔으면 answer배열에 넣어준다. 

이런식으로 인덱스를 적절히 조절하면서 idx1 > 0 && idx2 > 0 일때까지 본다.

마지막부터 봤으므로 reverse함수를 통해 answer를 뒤집어 주고 출력하면 끝이다!
```cpp
int idx1=s1.size(), idx2=s2.size();
vector<char> answer;
while(idx1 > 0 && idx2 > 0){
    switch(dir[idx1][idx2]){
        case 1:
            idx1--;
            break;
        case 2:
            idx2--;
            break;
        case 3:
            answer.push_back(s1[idx1-1]);
            idx1--; idx2--;
            break;
        default:
            break;
    }
}
reverse(answer.begin(), answer.end());
```

## 11054. 가장 긴 바이토닉 부분 수열 (골드 3)
앞에서 부터 볼 때와 뒤에서부터 볼때의 Dp를 다르게 하기 위해서 Dp배열을 두개 만들었다.

그리고 나서, dp[i] + dp2[i]의 최대값을 찾고, 중간에 겹쳐진 숫자를 뺀 정답을 출력한다.

* dp : 앞에서부터 봤을 때 현재까지의 가장 긴 수열의 크기
* dp2 : 뒤에서부터 봤을 때 현재까지의 가장 긴 수열의 크기

```cpp
for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        if(arr[i] < arr[j]){
            if(dp[j] < dp[i] + 1){
                dp[j] = dp[i] + 1;
            }
        }
    }
}

for(int i=n-1; i>=0; i--){
    for(int j=i-1; j>= 0; j--){
        if(arr[i] < arr[j]){
            if(dp2[j] < dp2[i] + 1){
                dp2[j] = dp2[i] + 1;
            }
        }
    }
}
```



## 1520. 내리막 길 (골드 4)
일반적인 dfs로 문제를 풀었더니 시간초과가 났다.

그래서 메모이제이션으로 시간을 줄여야 하는구나..!라고 생각했다.

dp의 각 요소가 의미하는것은 현재까지의 경로의 수이다.

그래서 초기값으로 -1으로 설정한다.

만약 dp[x][y] != -1 이면 경로가 있다는 얘기니까 return dp[x][y]을 한다.

그렇지 않으면 0으로 설정해서 아직까지 경로가 없다고 설정한다.

목적지에 도착했을 때, 경로가 있다는 의미로 1을 리턴하고 현재까지의 경로의 수에 더해준다.
```cpp
int dfs(int x, int y){
    if(x==n-1 && y==m-1){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    dp[x][y] = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m){
            continue;
        }
        if(arr[x][y] > arr[nx][ny]){
            dp[x][y] += dfs(nx, ny);
        }
    }
    return dp[x][y];
}
```



## 1915. 가장 큰 정사각형
### 구현
만약 arr[i][j]가 0이 아니면 자기 자신을 기준으로 왼쪽 위 정사각형 부분을 보고 가장 작은 숫자에 1을 더해준다.

이게 의미하는게 현재 보는 위치의 정사각형의 수이다. 만약 세칸 중 하나라도 0이 있다면 현재 정사각형은 자기 자신 뿐이라는 의미이다.

```cpp
int Max = 0;
for(int i=1; i<n+1; i++){
    for(int j=1; j<m+1; j++){
        if(arr[i][j] != 0){
            arr[i][j] = min(arr[i-1][j-1], min(arr[i][j-1], arr[i-1][j]))+1;
            Max = max(Max, arr[i][j]);
        }
    }
}
```

## 12865. 평범한 배낭
물건 개수마다의 무게를 1부터 K까지 본다. 현재 dp[i][j]의 값은 이전 무게 개수에서 현재 무게를 뺀 값에 현재 가치를 더한 값과 바로 이전의 가치값을 비교해서 더 큰 것을 넣는다.
```cpp
for(int i=1; i<n+1; i++){
    for(int j=1; j<k+1; j++){
        if(j >= w[i]){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
        }else{
            dp[i][j] = dp[i-1][j];
        }
    }
}
```







