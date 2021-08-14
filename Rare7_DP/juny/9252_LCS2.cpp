#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define endl '\n'
#define MAX 1001

int dp[MAX][MAX];
string str1, str2, res;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> str1 >> str2;

    for(int i = 0; i < str1.length(); i++) {
        for(int j = 0; j < str2.length(); j++) {
            if(str1[i] == str2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    
    cout << dp[str1.length()][str2.length()] << endl;

    int i = str1.length();
    int j = str2.length();
    res = "";

    while(dp[i][j] != 0) {
        if(dp[i][j] == dp[i-1][j]) i--;
        else if(dp[i][j] == dp[i][j-1]) j--;
        else {
            res = str1[i-1] + res;
            i--;
            j--;
        }
    }

    cout << res << endl;

    return 0;
}