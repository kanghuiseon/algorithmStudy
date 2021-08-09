#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define MAX_INDEX 102
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int arr[MAX_INDEX][MAX_INDEX];
int check[MAX_INDEX][MAX_INDEX];
vector<pair<int, int>> light[MAX_INDEX][MAX_INDEX];
int n, m;
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        light[x][y].push_back(make_pair(a, b));
    }
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    arr[1][1] = 1;
    check[1][1] = 1;
    int cnt = 1;
    bool flag = false;
    while(!q.empty()){
        flag = false;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(arr[x][y] != 2){
            for(auto a: light[x][y]){
                if(arr[a.first][a.second] != 0){
                    continue;
                }
                arr[a.first][a.second] = 1;
                flag = true;
                cnt++;
            }
        }
        arr[x][y] = 2;
        if(flag){
            for(int i=1; i<n+1; i++){
                for(int j=1; j<n+1; j++){
                    check[i][j] = 0;
                }
            }
            while(!q.empty())
                q.pop();
            q.push(make_pair(x, y));
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <= 0 || nx > n || ny <= 0 || ny > n || arr[nx][ny] == 0 || check[nx][ny])
                continue;
            q.push(make_pair(nx, ny));
            check[nx][ny] = 1;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

