#include <iostream>
#include <queue>

using namespace std;
#define MAX 201

int K, W, H;
int map[MAX][MAX];
bool visit[MAX][MAX][31];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int hdx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hdy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int bfs() {
    queue< pair< pair< int,int >, pair< int,int> > > q;
    q.push(make_pair(make_pair(0,0),make_pair(0,0)));
    visit[0][0][0] = true;

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int ability = q.front().second.second;
        q.pop();

        if(x == H-1 && y == W-1) return cnt;

        if(ability < K) {
            for(int i = 0; i < 8; i++) {
                int nx = x + hdx[i];
                int ny = y + hdy[i];

                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(map[nx][ny] == 1 || visit[nx][ny][ability+1]) continue;

                visit[nx][ny][ability+1] = true;
                q.push(make_pair(make_pair(nx,ny),make_pair(cnt+1,ability+1)));;
            }
        }

        for(int i = 0; i < 4;i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(map[nx][ny] == 1 || visit[nx][ny][ability]) continue;

            visit[nx][ny][ability] = true;
            q.push(make_pair(make_pair(nx,ny),make_pair(cnt+1,ability)));
        }
    }
    return -1;
}

int main() {
    cin >> K;
    cin >> W >> H;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++){
            cin >> map[i][j];
        }
    }

    cout << bfs() << endl;

    return 0;
}