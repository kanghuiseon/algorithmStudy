#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define MAX 10001

int N, M;
int parent[MAX];
char gender[1001];
vector< pair< int,pair<int,int> > > edge;

int find(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(x > y) parent[x] = y;
    else parent[y] = x;
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) parent[i] = i;
    for(int i = 1; i <= N; i++) cin >> gender[i];

    for(int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if(gender[u] != gender[v]) edge.push_back(make_pair(d,make_pair(u,v)));
    }

    sort(edge.begin(), edge.end());

    int res, cnt = 0;
    for(int i = 0; i < edge.size() && cnt != N-1; i++) {
        int d = edge[i].first;
        int u = edge[i].second.first;
        int v = edge[i].second.second;

        if(find(u) == find(v)) continue;
        merge(u,v);
        res += d;
        cnt++;
    }

    if(cnt == N-1) cout << res << endl;
    else cout << "-1" << endl;

    return 0;
}