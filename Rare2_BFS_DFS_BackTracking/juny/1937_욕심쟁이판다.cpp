#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 501

int n;
int map[MAX][MAX];
int dp[MAX][MAX];
int res;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int dfs(int x, int y) {
    if(dp[x][y]) return dp[x][y];

    dp[x][y] = 1;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(map[x][y] >= map[nx][ny]) continue;

        dp[x][y] = max(dp[x][y], dfs(nx,ny)+1);
    }
    return dp[x][y];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res = max(res, dfs(i,j));
        }
    }

    cout << res << endl;

    return 0;
}