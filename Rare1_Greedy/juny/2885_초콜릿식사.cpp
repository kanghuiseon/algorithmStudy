#include <stdio.h>

int main() {
    int K;
    scanf("%d", &K);

    int N = 1;
    while(N < K) N *= 2;
    
    int tmp_N = N;
    int tmp_K = K;
    int cnt = 0;
    while(tmp_N > 1) {
        if(tmp_K%tmp_N == 0) break;
        else if(tmp_K < tmp_N) {
            cnt++;
            tmp_N = tmp_N/2;
        }
        else {
            cnt++;
            tmp_N = tmp_N/2;
            tmp_K -= tmp_N;
        }
    }

    printf("%d %d\n", N, cnt);

    return 0;
}