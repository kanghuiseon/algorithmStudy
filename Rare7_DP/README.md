# Dynamic Programming(DP)
> 동적 계획법.  
```
! 분할 정복과 같은 접근 방식으로, 문제를 더 작은 문제로 나눠서 푸는 방법.  
분할 정복과의 차이는 중복되는 부분 문제를 계산하는 데 딱 한번만 계산하고 이를 재활용하는 것!  
```

## Memoization  
> 한번 계산한 값을 저장해 뒀다가 재활용하는 최적화 기법.  
> 무엇을 어떻게 기억하고 있을 지가 중요!!  
### 구조
```python
def memoization() :
    # 기저 사례
    if ... : return ...

    # 이미 계산해놓은 값
    if dp != -1 : return dp

    # 값 계산.
```
### 예시
**1** Bottom-up  
순서 : 문제를 작은 문제로 -> 작은 문제 풀고 -> 그걸 이용해 문제 풀기.  
```python
dp = [-1 for _ in range(N)]
def fibo(n) :
    # 기저 사례
    if (n <= 1) : 
    	return n
    else :
        # 이미 계산해놓은 값
        if dp[n] != -1 : return dp[n]
        # 값 계산
        dp[n] = fibo(n-1) + fibo(n-2)
        return dp[n]
```
**2** Top-down  
순서 : 작은 문제 풀기 -> 크기 키워가며 문제 풀기 -> n 까지 반복.  
```python
dp = [-1 for _ in range(N)]
def fibo(n) :
    # 기저 사례
    dp[0] = 0; dp[1] = 1
    for i in range(2,n+1) :
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]
```