#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 21

int R, C;
char board[MAX][MAX];
bool visit[26];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int res = -1;

void dfs(int x, int y, int cnt) {
    res = max(res,cnt);

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= R || ny < 0 || ny >= C || visit[board[nx][ny]-'A']) continue;

        visit[board[nx][ny]-'A'] = true;
        dfs(nx,ny,cnt+1);
        visit[board[nx][ny]-'A'] = false;
        }
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    visit[board[0][0]-'A'] = true;
    dfs(0,0,1);
    cout << res << endl;

    return 0;
}