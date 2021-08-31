#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define endl '\n'
#define MAX 1001

int N, M;
int parent[MAX];
vector< pair<int,int> > v;
vector< pair<double,pair<int,int> > > edge;

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

double getDist(int x, int y) {
    return sqrt(pow(v[x].first - v[y].first,2) + pow(v[x].second - v[y].second, 2));
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    v.assign(N+1, pair<int,int>());
    
    for(int i = 0; i <= N; i++) parent[i] = i;

    for(int i = 1; i <= N; i++) {
        int a, b;
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 1; i < N; i++) {
        for(int j = i+1; j <= N; j++) {
            double dist = getDist(i,j);
            edge.push_back(make_pair(dist, make_pair(i,j)));
        }
    }

    sort(edge.begin(), edge.end());

    int cnt = 0;
    double res = 0.0;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if(merge(a,b)) cnt++;
    }

    for(int i = 0; i < edge.size() && cnt != N-1; i++) {
        if(merge(edge[i].second.first, edge[i].second.second)) {
            cnt++;
            res += edge[i].first;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << res << endl;

    return 0;
}