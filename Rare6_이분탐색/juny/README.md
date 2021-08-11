# 이분 탐색 (Binary Search)
> 탐색 기법 중 하나로, 원하는 탐색 범위를 두 부분으로 분할하여 찾는 방법이다.  
원래의 전부를 탐색하는 방법-`O(n)`-에 비해 탐색 속도가 빠르다-`O(log(n))`.  
**1.** 이분 탐색을 하기 전 `정렬`을 한다.  
**2.** `left`, `right`로 `mid` 값을 정한다.  
**3.** `mid` 값과 `구하고자 하는 값`을 `비교`한다.  
**4.** 비교할 때, 구하고자 하는 값이 더 크면 `left=mid+1` 로, 더 작으면 `right=mid-1` 로 만들어준다.  
**5.** `left>right` 가 될 때까지 2~4번을 반복한다.  

## 기본 코드
``` c++
whlie(left <= right) {
    int mid = (left + right) / 2;
    if(arr[mid] < findNum) left = mid + 1;
    else if(arr[mid] > findNum) right = mid - 1;
    else {
        result = mid;
        break;
    }
}
```

## 예제 문제

### [백준 2805번 나무 자르기](https://github.com/juny9610/algorithmStudy/blob/master/Rare6_이분탐색/juny/2805_나무자르기.cpp)
**시간 초과**
완전 탐색으로 구현하니 시간 초과가 떴다.

**틀렸습니다**
int -> long long 으로 해결했다.

**맞았습니다**
이분 탐색으로 구현하고 통과했다.

### [백준 3020번 개똥벌래](https://github.com/juny9610/algorithmStudy/blob/master/Rare6_이분탐색/juny/3020_개똥벌래.cpp)
`Lower bound`, `Upper bound`를 사용했다.
`Lower boud`는 찾고자 하는 key값이 없으면 key값보다 `큰 가장 작은 정수값`을 찾는다.
> lower_bound(arr, arr+n, key);  
반환형이 iterator이므로 vector는 `v.begin()`을 뺀 값으로, 배열은 `배열의 첫번째 주소(배열의 이름)`을 뺀 값으로 위치를 찾는다.
`Upper bound`는 찾고자 하는 key값을 `초과하는 가장 첫 번째 값`의 위치를 구한다.
> upper_bound(arr, arr+n, key);  
반환형이 iterator이므로 vector는 `v.begin()`을 뺀 값으로, 배열은 `배열의 첫번째 주소(배열의 이름)`을 뺀 값으로 위치를 찾는다.

### [백준 9007번 카누 선수](https://github.com/juny9610/algorithmStudy/blob/master/Rare6_이분탐색/juny/9007_카누선수.cpp)
단순 구현은 4중 for문이지만 시간 초과에 걸린다.
1. 두 반씩 묶어서 새로운 배열 생성
2. 이를 이분 탐색으로 찾기

### [백준 12738번 가장 긴 증가하는 부분 수열 3](https://github.com/juny9610/algorithmStudy/blob/master/Rare6_이분탐색/juny/12738_가장긴증가하는부분수열3.cpp)
`lower_bound`를 사용해서 index를 찾아 최장 증가 부분 수열(Longest Increasing Subsequence)에 삽입한다.

### [백준 1365번 꼬인 전깃줄](https://github.com/juny9610/algorithmStudy/blob/master/Rare6_이분탐색/juny/1365_꼬인전깃줄.cpp)
`최장 증가 부분 수열` 임을 인지하고 풀면 간단히 해결된다.
