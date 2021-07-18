#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int check[202][202][32];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int hdx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int hdy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int main(){
    int w, h, k;
    cin >> k;
    cin >> w >> h;
    vector<vector<int>> arr(h, vector<int>(w, 0));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> arr[i][j];
        }
    }
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    for(int i=0; i<k+1; i++){
        check[0][0][i] = 1;
    }
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int hurdle = get<2>(q.front());
        q.pop();
        if(x == h-1 && y == w-1){
            cout << check[x][y][hurdle]-1 << endl;
            return 0;
        }
        if(hurdle+1 <= k){
            for(int i=0; i<8; i++){
                int nx = x + hdx[i];
                int ny = y + hdy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    continue;
                }
                if(check[nx][ny][hurdle+1] == 0 && arr[nx][ny] != 1){
                    check[nx][ny][hurdle+1] = check[x][y][hurdle] + 1;
                    q.push(make_tuple(nx, ny, hurdle+1));
                }
            }
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                continue;
            }
            if(arr[nx][ny] == 1 && hurdle+1 > k){
                continue;
            }
            else if(arr[nx][ny] == 0 && !check[nx][ny][hurdle]){
                check[nx][ny][hurdle] = check[x][y][hurdle] + 1;
                q.push(make_tuple(nx, ny, hurdle));
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}
