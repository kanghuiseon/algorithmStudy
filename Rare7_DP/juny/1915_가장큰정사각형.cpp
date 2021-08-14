#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define endl '\n'
#define MAX 1001

int n, m;
int arr[MAX][MAX];
int dp[MAX][MAX];
int res = 0;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    for(int i = 0; i < n; i++) dp[i][0] = arr[i][0];
    for(int i = 0; i < m; i++) dp[i][0] = arr[0][i];

    res = dp[0][0];

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(arr[i][j] == 1) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                if(res < dp[i][j]) res = dp[i][j];
            }
        }
    }

    cout << res*res << endl;

    return 0;
}