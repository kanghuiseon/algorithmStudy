#include <iostream>
#include <vector>
using namespace std;

#define MAX 501
#define INF 1e9

int TC, N, M, W;
int from, to, cost;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> TC;
    while(TC--) {
        cin >> N >> M >> W;

        vector< pair<int,int> > map[N+1];
        vector<int> dist(N+1, INF);
        dist[1] = 0;

        for(int i = 0; i < M; i++) {
            cin >> from >> to >> cost;
            map[from].push_back(make_pair(to,cost));
            map[to].push_back(make_pair(from,cost));
        }
        for(int i = 0; i < W; i++) {
            cin >> from >> to >> cost;
            map[from].push_back(make_pair(to,(-1)*cost));
        }

        bool cycle = false;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                for(int k = 0; k < map[j].size(); k++) {
                    int next = map[j][k].first;
                    int cost = map[j][k].second;
                    if(dist[next] > cost + dist[j]) {
                        dist[next] = cost + dist[j];
                        if(i == N) cycle = true;
                    }
                }
            }
        }

    if(cycle) cout << "YES\n";
    else cout << "NO\n";
    }

    return 0;
}