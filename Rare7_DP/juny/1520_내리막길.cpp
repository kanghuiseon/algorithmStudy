#include <iostream>
using namespace std;

#define endl '\n'
#define MAX 501

int N, M, res = 0;
int arr[MAX][MAX], dp[MAX][MAX];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int dfs(int x, int y) {
    if(x == N-1 && y == M-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 ||ny < 0 || nx >= N || ny >= M) continue;
        if(arr[nx][ny] < arr[x][y]) dp[x][y] = dp[x][y] + dfs(nx,ny);
    }

    return dp[x][y];
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    res = dfs(0,0);
    cout << res << endl;

    return 0;
}