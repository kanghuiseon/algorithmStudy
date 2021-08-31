// 크루스칼 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define MAX 10001

int V, E;
int parent[MAX];
vector< pair< int,pair<int,int> > > v;

int find(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    
    if(x != y) parent[y] = x;
}


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(c, make_pair(a,b)));
    }

    sort(v.begin(), v.end());

    for(int i = 1; i <= V; i++) parent[i] = i;

    int res = 0;
    for(int i = 0; i < E; i++) {
        if(find(v[i].second.first) != find(v[i].second.second)) {
            Union(v[i].second.first, v[i].second.second);
            res += v[i].first;
        }
    }

    cout << res << endl;

    return 0;
}