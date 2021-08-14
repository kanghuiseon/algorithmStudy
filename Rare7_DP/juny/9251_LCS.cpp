#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define endl '\n'

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;
    int dp[1001][1001];

    for(int i = 0; i < str1.length(); i++) {
        for(int j = 0; j < str2.length(); j++) {
            if(str1[i] == str2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    
    cout << dp[str1.length()][str2.length()];

    return 0;
}