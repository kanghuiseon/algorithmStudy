#include <iostream>
#include <queue>

using namespace std;
#define MAX 1001

int N, M, V;
int arr[MAX][MAX];
bool visit[MAX];
queue<int> q;

void dfs(int v) {
    visit[v] = true;
    cout << v << " ";

    for(int i = 1; i <= N; i++) {
        if(arr[v][i] == 1 && visit[i] == 0) dfs(i);
    }
}

void bfs(int v) {
    q.push(v);
    visit[v] = true;
    cout << v << " ";

    while(!q.empty()) {
        v = q.front();
        q.pop();

        for(int i = 1; i <= N; i++) {
            if(arr[v][i] == 1 && visit[i] == 0) {
                q.push(i);
                visit[i] = true;
                cout << i << " ";
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(int i = 1; i <= N; i++) visit[i] = 0;
    dfs(V);
    printf("\n");
    for(int i = 1; i <= N; i++) visit[i] = 0;
    bfs(V);
    printf("\n");

    return 0;
}