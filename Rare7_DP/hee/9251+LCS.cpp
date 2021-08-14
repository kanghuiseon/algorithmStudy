#include <iostream>
#include <algorithm>
#define MAX_INDEX 1004
using namespace std;
int dp[MAX_INDEX][MAX_INDEX];
int main(){
    string s1, s2;
    cin >> s1 >> s2;
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
    return 0;
}

