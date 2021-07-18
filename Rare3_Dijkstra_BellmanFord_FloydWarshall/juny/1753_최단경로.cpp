#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 20001
#define INF 2147483647

int V, E, K;
vector< pair<int,int> > map[MAX];
int dist[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;

    for(int i = 1; i <= V; i++) dist[i] = INF;
    
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b,c));
    }

    priority_queue< pair<int,int> > pq;

    pq.push(make_pair(0,K));
    dist[K] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i].first;
            int n_cost = map[cur][i].second;

            if(dist[next] > cost + n_cost) {
                dist[next] = cost + n_cost;
                pq.push(make_pair(-dist[next],next));
            }
        }
    }

    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}