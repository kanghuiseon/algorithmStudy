#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(101, vector<int>(100001,0));
    vector<int> w(n+1);
    vector<int> v(n+1);
    for(int i=1; i<n+1; i++){
        cin >> w[i];
        cin >> v[i];
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<k+1; j++){
            if(j < w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
        }
    }
    printf("%d\n", dp[n][k]);
    return 0;
}

