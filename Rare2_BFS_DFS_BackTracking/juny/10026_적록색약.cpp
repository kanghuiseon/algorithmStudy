#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 101

int N;
char arr[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    queue< pair<int,int> > q;

    q.push(make_pair(x,y));
    visit[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx > -1 && nx < N && ny > -1 && ny < N) {
                if(!visit[nx][ny]) {
                    if(arr[x][y] == arr[nx][ny]) {
                        q.push(make_pair(nx, ny));
                        visit[nx][ny] = true;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visit[i][j]) {
                bfs(i,j);
                cnt++;
            }
        }
    }

    printf("%d ", cnt);

    memset(visit, false, sizeof(visit));
    cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == 'G') arr[i][j] = 'R';
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visit[i][j]) {
                bfs(i,j);
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);    

    return 0;
}