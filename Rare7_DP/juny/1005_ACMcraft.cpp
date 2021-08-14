#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'
#define MAX 1001

int T, N, K, W;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> N >> K;

        int time[MAX];
        for(int i = 1; i <= N; i++) cin >> time[i];

        vector<int> building[MAX];
        int order[MAX] = {0};
        for(int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            building[a].push_back(b);
            order[b]++;
        }

        int W;
        cin >> W;

        int res[MAX] = {0};
        queue<int> q;
        for(int i = 1; i <= N; i++) {
            if(order[i] == 0) {
                q.push(i);
                res[i] = time[i];
            }
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            if(cur == W) break;

            for(int i = 0; i < building[cur].size(); i++) {
                int next = building[cur][i];
                res[next] = max(res[next], res[cur] + time[next]);
                order[next]--;

                if(order[next] == 0) q.push(next);
            }
        }

        cout << res[W] << endl;

    }

    return 0;
}