#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INDEX 104
using namespace std;
int dp[MAX_INDEX][MAX_INDEX][MAX_INDEX];
// abcdefghijklmn
// bdefg
// efg

int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            for(int k=0; k<s3.size(); k++){
                if(s1[i] == s2[j] && s2[j] == s3[k]){
                    dp[i+1][j+1][k+1] = dp[i][j][k]+1;
                }else{
                    dp[i+1][j+1][k+1] = max(dp[i][j+1][k+1], max(dp[i+1][j][k+1], dp[i+1][j+1][k]));
                }
            }
        }
    }
    printf("%d\n", dp[s1.size()][s2.size()][s3.size()]);
    return 0;
}

