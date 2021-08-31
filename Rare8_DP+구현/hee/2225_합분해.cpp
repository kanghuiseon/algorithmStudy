#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INDEX 202
using namespace std;
long long int dp[MAX_INDEX][MAX_INDEX];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n+1; i++){
        dp[1][i] = 1;
    }
    
    for(int i=2; i<k+1; i++){
        for(int j=0; j<n+1; j++){
            for(int p=0; p<j+1; p++){
                dp[i][j] += dp[i-1][p];
            }
            dp[i][j] %= 1000000000;
        }
    }
    printf("%lld\n", dp[k][n]);
    return 0;
}
