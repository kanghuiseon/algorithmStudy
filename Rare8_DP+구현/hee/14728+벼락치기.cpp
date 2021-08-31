#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INDEX 10004
using namespace std;
int dp[102][MAX_INDEX];
int tt[1002];
int score[1002];
int main(){
    int n, t;
    scanf("%d %d", &n, &t);
    for(int i=1; i<n+1; i++){
        int k, s;
        scanf("%d %d", &k, &s);
        tt[i] = k;
        score[i] = s;
    }
    for(int i=1; i<n+1; i++){
        for(int j=0; j<t+1; j++){
            if(j >= tt[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-tt[i]] + score[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("%d\n", dp[n][t]);
    return 0;
}
