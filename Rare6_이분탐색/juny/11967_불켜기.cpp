#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
#define MAX 101

int N, M;
vector< pair<int,int> > map[MAX][MAX];
int visit[MAX][MAX]; // 0: 아무것도 아님, 1: 불이 켜짐, 2: 방문 완료

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        map[x][y].push_back(make_pair(a,b));
    }

    queue< pair<int,int> > q;
    q.push(make_pair(1,1));
    visit[1][1] = 2;

    int res = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < map[x][y].size(); i++) {
            int nx = map[x][y][i].first;
            int ny = map[x][y][i].second;
            if(!visit[nx][ny]) {
                for(int d = 0; d < 4; d++) {
                    int nnx = nx + dx[d];
                    int nny = ny + dy[d];
                    if(visit[nnx][nny] == 2) { // 방문 완료했어도 방문할 수는 있다.
                        q.push(make_pair(nnx,nny));
                        break;
                    }
                }
                visit[nx][ny] = 1;
                res++;
            }
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(visit[nx][ny] == 1) {
                visit[nx][ny] = 2;
                q.push(make_pair(nx,ny));
            }
        }
    }

    cout << res << endl;

    return 0;
}