#include <iostream>
using namespace std;

#define endl '\n'
#define MAX 1000001

int n, m;
int parent[MAX];

int find(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(x > y) parent[x] = y;
    else parent[y] = x;
}


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i <= n; i++) parent[i] = i;
    while(m--) {
        int c, a, b;
        cin >> c >> a >> b;
        if(c == 0) merge(a,b);
        else if(c == 1) {
            if(find(a) == find(b)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}