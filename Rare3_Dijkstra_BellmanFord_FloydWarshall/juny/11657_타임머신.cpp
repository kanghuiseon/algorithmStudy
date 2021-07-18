#include <iostream>
#include <vector>

using namespace std;
#define MAX 501
#define INF 2147483647

int N, M;
int A, B, C;
vector< pair<int,int> > map[MAX];
long long dist[MAX];
bool cycle = false;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        map[A].push_back(make_pair(B,C));
    }

    for(int i = 1; i <= N; i++) dist[i] = INF;

    dist[1] = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 0; k < map[j].size(); k++) {
                int next = map[j][k].first;
                int cost = map[j][k].second;
                if(dist[j] != INF && dist[next] > cost + dist[j]) {
                    dist[next] = cost + dist[j];
                    if(i == N) cycle = true;
                }
            }
        }
    }

    if(cycle) cout << "-1\n";
    else {
        for(int i = 2; i <= N; i++) {
            if(dist[i] == INF) cout << "-1\n";
            else cout << dist[i] << "\n";
        }
    }

    return 0;
}