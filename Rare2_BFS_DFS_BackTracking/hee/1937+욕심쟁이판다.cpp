#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n;
int arr[501][501];
int Max = -1;
int check[501][501];
int cnt=0;
int dfs(int x, int y){
    if(check[x][y] != 0)
        return check[x][y];
    check[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if(arr[nx][ny] > arr[x][y]){
            int cnt = dfs(nx, ny);
            check[x][y] = max(check[x][y], cnt+1);
        }
    }
    return check[x][y];
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt = dfs(i, j);
            Max = max(Max, cnt);
        }
    }
    cout << Max << endl;
    return 0;
}

