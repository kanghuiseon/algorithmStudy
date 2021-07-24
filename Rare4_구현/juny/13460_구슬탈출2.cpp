#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define endl '\n'
#define MAX 11

int N, M;
char map[MAX][MAX];
bool visit[MAX][MAX][MAX][MAX];
int rx, ry, bx, by;
int result;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs() {
    queue< pair<int,int> > red;
    queue< pair<int,int> > blue;
    red.push(make_pair(rx,ry));
    blue.push(make_pair(bx,by));
    visit[rx][ry][bx][by] = true;

    while(!red.empty()) {
        int size = red.size();

        while(size--) {
            int r_cx = red.front().first;
            int r_cy = red.front().second;
            int b_cx = blue.front().first;
            int b_cy = blue.front().second;

            red.pop();
            blue.pop();

            if(map[r_cx][r_cy] == 'O') return result;

            for(int i = 0; i < 4; i++) {
                int r_nx = r_cx;
                int r_ny = r_cy;
                int b_nx = b_cx;
                int b_ny = b_cy;
                
                // 이동할 곳이 #이 아니고 현재 좌표가 O가 아니라면 계속 이동
                while(map[r_nx+dx[i]][r_ny+dy[i]] != '#' && map[r_nx][r_ny] != 'O') {
                    r_nx += dx[i];
                    r_ny += dy[i];
                }
                while(map[b_nx+dx[i]][b_ny+dy[i]] != '#' && map[b_nx][b_ny] != 'O') {
                    b_nx += dx[i];
                    b_ny += dy[i];
                }

                if(r_nx == b_nx && r_ny == b_ny) {
                    // 두 좌표 모두 O라면 실패이므로 continue
                    if(map[r_nx][r_ny] == 'O') continue;
                    // 두 좌표 모두 한쪽 끝이라면 비교 후 하나를 이동
                    if(abs(r_nx-r_cx) + abs(r_ny-r_cy) > abs(b_nx-b_cx) + abs(b_ny-b_cy)) {
                        r_nx -= dx[i];
                        r_ny -= dy[i];
                    }
                    else {
                        b_nx -= dx[i];
                        b_ny -= dy[i];
                    }
                }

                if(visit[r_nx][r_ny][b_nx][b_ny]) continue;

                red.push(make_pair(r_nx,r_ny));
                blue.push(make_pair(b_nx,b_ny));
                visit[r_nx][r_ny][b_nx][b_ny] = true;
            }
        }
        if(result == 10) return -1;
        result++;
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    string st;
    for(int i = 0; i < N; i++) {
        cin >> st;
        for(int j = 0; j < M; j++) {
            map[i][j] = st[j];
            if(st[j] == 'R') { rx = i; ry = j; map[i][j] = '.';}
            if(st[j] == 'B') { bx = i; by = j; map[i][j] = '.';}
        }
    }
    int res = bfs();
    cout << res << endl;

    return 0;
}