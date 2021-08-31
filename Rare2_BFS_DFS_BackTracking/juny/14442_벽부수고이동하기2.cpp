#include <iostream>
#include <string>
#include <queue>

using namespace std;
#define MAX 1001

int N, M, K;
int map[MAX][MAX];
bool visit[MAX][MAX][11];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs() {
    queue< pair< pair<int,int>, pair<int,int> > > q;
    q.push(make_pair(make_pair(0,0),make_pair(1,0)));
    visit[0][0][0] = true;

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int w = q.front().second.second;
        q.pop();

        if(x == N-1 && y == M-1) return cnt;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visit[nx][ny][w]) continue;

            if(map[nx][ny] == 0) {
                visit[nx][ny][w] = true;
                q.push(make_pair(make_pair(nx,ny), make_pair(cnt+1,w)));
            }
            else if(map[nx][ny] == 1) {
                if(w < K){
                    visit[nx][ny][w+1] = true;
                    q.push(make_pair(make_pair(nx,ny), make_pair(cnt+1,w+1)));
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < M; j++) {
            map[i][j] = tmp[j] - '0';
        }
    }

    cout << bfs() << endl;

    return 0;
}