#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int t, n;
vector< pair<int,int> > v(105);
bool visit[105];

void bfs(int idx) {
    queue<int> q;
    q.push(idx);
    visit[idx] = true;

    while(!q.empty()) {
        idx = q.front();
        q.pop();

        for(int i = 1; i < n+2; i++) {
            if(visit[i]) continue;
            if(abs(v[idx].first - v[i].first) + abs(v[idx].second - v[i].second) <= 1000) {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        
        for(int i = 0; i < n+2; i++) {
            cin >> v[i].first >> v[i].second;
        }

        bfs(0);

        if(visit[n+1]) cout << "happy" << endl;
        else cout << "sad" << endl;

        memset(visit, 0, sizeof(visit));
        
    }
    return 0;
}