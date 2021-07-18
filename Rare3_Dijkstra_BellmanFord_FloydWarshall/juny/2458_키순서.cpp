#include <iostream>
using namespace std;

#define INF 214748364
#define MAX 501

int N, M, a, b;
int map[MAX][MAX];

void floyd() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            map[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        map[a][b] = 1;
    }

    floyd();

    int res = 0;
    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        for(int j = 1; j <= N; j++) {
            if(map[i][j] != INF || map[j][i] != INF) {
                cnt++;
            }
        }
        if(cnt == N-1) res++;
    }

    cout << res << endl;

    return 0;
}