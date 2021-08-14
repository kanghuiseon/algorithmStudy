#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INDEX 1004
using namespace std;
int dp[MAX_INDEX][MAX_INDEX];
int dir[MAX_INDEX][MAX_INDEX];
int main(){
    string s1, s2;
    cin >> s2 >> s1;
    // 1: 위, 2: 왼, 3: 대각선
//    vector<int> dir;
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if(s1[i] == s2[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                dir[i+1][j+1] = 3;
            }
            else{
                // 위, 왼
                if(dp[i][j+1] > dp[i+1][j]){
                    dp[i+1][j+1] = dp[i][j+1];
                    dir[i+1][j+1] = 1;
                }else if(dp[i][j+1] < dp[i+1][j]){
                    dp[i+1][j+1] = dp[i+1][j];
                    dir[i+1][j+1] = 2;
                }
                else{
                    dp[i+1][j+1] = dp[i][j+1];
                    dir[i+1][j+1] = 1;
                }
            }
        }
    }
    printf("%d\n", dp[s1.size()][s2.size()]);
    int idx1=s1.size(), idx2=s2.size();
    vector<char> answer;
    while(idx1 > 0 && idx2 > 0){
        switch(dir[idx1][idx2]){
            case 1:
                idx1--;
                break;
            case 2:
                idx2--;
                break;
            case 3:
                answer.push_back(s1[idx1-1]);
                idx1--; idx2--;
                break;
            default:
                break;
        }
    }
    reverse(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++){
        cout << answer[i];
    }
    cout << "\n";
    return 0;
}

