#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int K, V, E;
vector<int> graph[20001];
int visit[20001] = {0};

void bfs(int idx) {
    queue<int> q;
    int num = 1;
    visit[idx] = num;
    q.push(idx);

    while(!q.empty()) {
        idx = q.front();
        q.pop();

        if(visit[idx] == 1) num = 2;
        else num = 1;

        for(int i = 0; i < graph[idx].size(); i++) {
            int next = graph[idx][i];
            if(!visit[next]) {
                visit[next] = num;
                q.push(next);
            }
        }
    }
}

bool isBinary() {
    for(int i = 1; i <= V; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            int next = graph[i][j];
            if(visit[i] == visit[next]) return false;
        }
    }
    return true;
}

int main() {
    cin >> K;
    while(K--) {
        cin >> V >> E;
        for(int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i = 1; i <= V; i++) {
            if(!visit[i]) bfs(i);
        }
        /*
        bool flag = false;
        for(int i = 1; i <= V; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                int next = graph[i][j];
                if(visit[i] == visit[next]) flag = true;
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;
        */
        if(isBinary()) cout << "YES" << endl;
        else cout << "NO" << endl;

        for(int i = 0; i <= V; i++) {
            graph[i].clear();
        }
        memset(visit, false, sizeof(visit));
    }

    return 0;
}