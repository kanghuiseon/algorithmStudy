#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
bool check[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;
string arr[101];
void dfs(int x, int y){
    check[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(-1<nx && -1<ny && nx<n && ny<n){
            if(!check[nx][ny] && arr[x][y] == arr[nx][ny])
                dfs(nx, ny);
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    printf("%d ", cnt);
    cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 'G')
                arr[i][j] = 'R';
        }
    }
    memset(check, false, sizeof(check));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}

