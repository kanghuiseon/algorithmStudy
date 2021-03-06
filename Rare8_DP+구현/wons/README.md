## [2225 합분해](./2225_합분해.py)
점화식을 잘 구해야 되는 문제. `k==1` 이면 항상 1. `n==1` 이면 k랑 같음.  
그렇게 표로 그려보면 `dp[i][j] = dp[i-1][j]+dp[i][j-1]` 을 구할 수 있다.  

## [2533 사회망서비스](./2533_사회망서비스.py)
해당 노드에서 인플루언서 인지 아닌지를 고려해서 dfs 를 돌면 된다.  
`dp[cur][0]` 은 인플루언서가 아닐때, `dp[cur][1]` 은 인풀루언서 일때로 풀어줬다.  

## [1958 LCS3](./1958_LCS3.py)
`9251_LCS` 문제와 동일하게 풀어주면된다.  
`max` 값을 가져오는 부분에서 모든 경우를 고려해주어야 한다.  

## [14728 벼락치기](./14728_벼락치기.py)
전형적인 냅색 문제다. [12865 평범한배낭](../../Rare7_DP/wons/12865_평범한배낭.py) 과 같은 문제.  

## [2045 마방진](./2045_마방진.py)
마방진의 가로/세로/대각선 이 모두 0 인 경우 합을 구하는 방법 : `sum(board)//2`.  
한 줄에 0 이 1개인 경우에 채워주도록 풀었는 데 반례 : [0,0,12],[0,10,4],[8,8,14] 면 못품. so 최대 0이 3개임으로 3번 돌려줌.  

## [16472 고냥이](./16472_고냥이.py)
`투 포인터` 와 `Counter` 조합으로 풀었다.  
`L`,`R` 포인터로 문자열의 알파벳을 보면서 같은 경우엔 `R+=1` 아닌 경우엔 `R+=1` 후 종류가 N개가 되도록 `L+=1` 해준다.  

## [21923 곡예비행](./21923_곡예비행.py)
컨셉(2개의 dp 배열(상승/하강))은 바로 알았는데 음수처리때문에 조금 애먹었던 문제.  
처음엔 단순히 이전꺼에 `max` 를 봐줬는데 음수가 들어온다는 점을 간과했다.  
그래서 `N-1`,`M-1`,`0` 인 경우에 따로 처리해줘서 풀었다.  
그리고 결과가 음수가 나올 수 도 있어서 `ans=-int(1e9)` 로 설정해줌.  
