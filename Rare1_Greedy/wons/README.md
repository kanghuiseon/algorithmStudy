## [13305 주유소](./13305_주유소.py)
가장 싼 주유소 가격 기억 후 주유소 들릴때마다 선택

## [1543 문서 검색](./1543_문서검색.py)
왜 그리디??? 그냥 브루스 포스 아닌가

## [2885 초콜릿 식사](./2885_초콜릿식사.py)
N/2 가 K 보다 클수 있을 거라는 점 간과. -> while 돌려줘야함.

## [2831 댄스파티](./2831_댄스파티.py)
각 조건에 맞는 경우를 분리해서 최대로 만들수 있는경우로 조합
최대로 만들수 있는 경우 -> 키 차이가 가장작을 때!

## [1202 보석 도둑](./1202_보석도둑.py)
가방에 넣을 수 있는 보석의 경우 가격을 pq 에 넣어서 보관.  
-> 처음에 단순히 가방끼리만 비교하니까 안됨. pq를 가지고 최고가 뽑아줘야댐.

## [2812 크게 만들기](./2812_크게만들기.py)
단순하게 i-1 < i 인 경우 i-1 지우는 방법 -> O(N^2) 시간초과.  
알고리즘분류에 스택 적혀있는거 보고 힌트얻어서 풀었쪙.  
각 숫자 확인하면서 stack 에 가장 최근값 보다 크면 stack 에서 빼줌.  

## [1114 통나무자르기](1114_통나무자르기.py)
이분탐색으로 풀수 있을 것 같은데 잘안된다.  