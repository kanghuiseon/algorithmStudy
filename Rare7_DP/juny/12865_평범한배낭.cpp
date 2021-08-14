#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define MAX 101

int N, K;
int weigh[MAX], value[MAX];
int dp[MAX][100001];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> weigh[i] >> value[i];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(j >= weigh[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-weigh[i]] + value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}