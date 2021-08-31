#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define MAX 500001

int n, m, res;
int parent[MAX];

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

    cin >> n >> m;
    for(int i = 0; i < n; i++) parent[i] = i;

    vector< pair<int,int> > v;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }

    for(int i = 0; i < v.size(); i++) {
        int a = v[i].first;
        int b = v[i].second;
        if(!merge(a,b)) {
            res = i+1;
            break;
        }
    }

    if(res == 0) cout << "0" << endl;
    else cout << res << endl;

    return 0;
}