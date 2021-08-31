#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'

int N, M, H, result = 987654321;
bool map[31][31];

bool check() {
    for(int i = 1; i <= N; i++) {
        int num = i;
        for(int j = 1; j <= H; j++) {
            if(map[j][num])  num++;
            else if(map[j][num-1]) num--;
        }
        if(num != i) return false;
    }
    return true;
}

void dfs(int idx, int cnt) {
    if(cnt > 3) return;

    if(check()) {
        result = min(result, cnt);
        return;
    }

    for(int i = idx; i <= H; i++) {
        for(int j = 1; j <= N; j++) {
            if(map[i][j] || map[i][j-1]) continue;
            map[i][j] = true;
            dfs(i,cnt+1);
            map[i][j] = false;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = true;
    }
    dfs(1,0);
    if(result == 987654321) result = -1;
    cout << result << endl;

    return 0;
}