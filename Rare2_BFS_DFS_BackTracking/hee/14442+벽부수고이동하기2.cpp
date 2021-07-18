#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int check[1003][1003][12];
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j] - '0';
        }
        
    }
    for(int i=0; i<k+1; i++){
        check[0][0][i] = 1;
    }
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int wall = get<2>(q.front());
        q.pop();
        if(x == n-1 && y == m-1){
            cout << check[x][y][wall] << endl;
            return 0;
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
            if(arr[nx][ny] == 1 && wall+1 <= k && check[nx][ny][wall+1] == 0){
                check[nx][ny][wall+1] = check[x][y][wall] + 1;
                q.push(make_tuple(nx, ny, wall+1));
            }
            else if(check[nx][ny][wall] == 0 && arr[nx][ny] == 0){
                check[nx][ny][wall] = check[x][y][wall] + 1;
                q.push(make_tuple(nx, ny, wall));
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}
