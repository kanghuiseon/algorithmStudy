#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INDEX 505
using namespace std;
int dp[MAX_INDEX][MAX_INDEX];
int arr[MAX_INDEX][MAX_INDEX];
int n, m;
// 왼, 오, 위, 아래
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int dfs(int x, int y){
    if(x==n-1 && y==m-1){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    dp[x][y] = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m){
            continue;
        }
        if(arr[x][y] > arr[nx][ny]){
            dp[x][y] += dfs(nx, ny);
        }
    }
    return dp[x][y];
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    printf("%d\n", dfs(0, 0));
    return 0;
}

