#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2147483647
#define MAX 101

int T, N, M, K;
int u, v, c, d;
vector< pair< int, pair<int,int> > > map[MAX];
int dist[MAX][10001];

void dijkstra() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) dist[i][j] = INF;
    }

    priority_queue< pair<int, pair<int,int> > > pq;
    dist[1][0] = 0;
    pq.push(make_pair(0,make_pair(0,1)));

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int time = pq.top().second.first;
        int cur = pq.top().second.second;
        pq.pop();

        if(dist[cur][cost] < time) continue;

        for(int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i].first;
            int n_cost = cost + map[cur][i].second.first;
            int n_time = time + map[cur][i].second.second;

            if(n_cost > M) continue;

            if(dist[next][n_cost] > n_time) {
                for(int i = n_cost; i <= M; i++) {
                    if(dist[next][i] > n_time) dist[next][i] = n_time;
                }
                pq.push(make_pair(-n_cost,make_pair(n_time,next)));
            }
        }
    }
    int res = INF;
    for(int i = 1; i <= M; i++) res = min(res, dist[N][i]);
    if(res == INF) cout << "Poor KCM\n";
    else cout << res << "\n";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> N >> M >> K;

        for(int i = 1; i <= N; i++) while(!map[i].empty()) map[i].pop_back();

        for(int i = 0; i < K; i++) {
            cin >> u >> v >> c >> d;
            map[u].push_back(make_pair(v,make_pair(c,d)));
        }
        dijkstra();

    }

    return 0;
}