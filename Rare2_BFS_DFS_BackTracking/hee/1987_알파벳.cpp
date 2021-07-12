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
vector<string> arr(21);
vector<vector<bool>> check(21, vector<bool>(21, false));
int alpha[26];
int r, c;
int Max = -1;
void dfs(int x, int y, int cnt){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || check[nx][ny] || alpha[arr[nx][ny]-'A'] == 1){
            Max = max(Max, cnt);
        }
        else{
            check[nx][ny] = true;
            alpha[arr[nx][ny] - 'A'] = 1;
            dfs(nx, ny, cnt+1);
            check[nx][ny] = false;
            alpha[arr[nx][ny] - 'A'] = 0;
        }
    }
}
int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        cin >> arr[i];
    }
    check[0][0] = true;
    alpha[arr[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << Max << endl;
    return 0;
}

