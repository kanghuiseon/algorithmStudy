#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int check[1001][1001][2];
int main(){
    int n, m;
    queue<tuple<int, int, bool>> q;
    cin >> n >> m;
    vector<string> arr(n);
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    q.push(make_tuple(0, 0, false));
    check[0][0][0] = 1;
    check[0][0][1] = 1;
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        // true : 부쉈다. false: 안부쉈다
        bool flag = get<2>(q.front());
        if(x == n-1 && y == m-1){
            cout<<  check[x][y][flag] << endl;
            return 0;
        }
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
            if(!flag && arr[nx][ny] == '1'){
                check[nx][ny][1] = check[x][y][0] + 1;
                q.push(make_tuple(nx, ny, true));
            }
            else if(!check[nx][ny][flag] && arr[nx][ny] == '0'){
                check[nx][ny][flag] = check[x][y][flag] + 1;
                q.push(make_tuple(nx, ny, flag));
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}
