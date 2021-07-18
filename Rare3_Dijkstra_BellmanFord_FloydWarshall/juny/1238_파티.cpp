#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
#define MAX 1001
#define INF 2147483647

int N, M, X;
vector< pair<int,int> > v[MAX];
int dist[MAX], res[MAX];
int from, to, cost;

void dijkstra(int start) {
   priority_queue< pair<int,int> > pq;

    pq.push(make_pair(0,start));
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int n_cost = v[cur][i].second;

            if(dist[next] > cost + n_cost) {
                dist[next] = cost + n_cost;
                pq.push(make_pair(-dist[next],next));
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;

    for(int i = 0; i < M; i++) {
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to,cost));
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j<= N; j++) dist[j] = INF;
        dijkstra(i);
        res[i] = dist[X];
    }

    for(int i = 1; i <= N; i++) dist[i] = INF;
    dijkstra(X);
    for(int i = 1; i <= N; i++) res[i] = res[i] + dist[i];

    int ans = -1;
    for(int i = 1; i <= N; i++) {
        ans = max(ans, res[i]);
    }

    cout << ans << endl;

    return 0;
}