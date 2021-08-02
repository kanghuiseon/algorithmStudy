#include <iostream>
using namespace std;

#define endl '\n'
#define MAX 201

int N, M;
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

    cin >> N >> M;
    for(int i = 0; i <= N; i++) parent[i] = i;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            if(tmp == 1) merge(i,j);
        }
    }

    int cur, next;
    bool flag = true;
    cin >> cur;
    for(int i = 1; i < M; i++) {
        cin >> next;
        if(!flag) continue;
        if(find(cur) != find(next)) flag = false;
        cur = next;
    }    
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}