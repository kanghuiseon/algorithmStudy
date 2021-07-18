#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101
#define INF 1e9

int N, M;
int arr[MAX][MAX];
int dist[MAX], res[MAX];
bool check[MAX];

void floyd() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
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
        for(int j = 1; j <= N; j++) if(i^j) arr[i][j] = INF;
    }

    for(int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }

    floyd();

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) if(arr[i][j] < INF && arr[i][j] > dist[i]) dist[i] = arr[i][j];
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(!check[i]) {
            int tmp = i;
            for(int j = i; j <= N; j++) {
                if(arr[i][j] < INF) {
                    check[j] = true;
                    if(dist[tmp] > dist[j]) tmp = j;
                }
            }
            res[cnt++] = tmp;
        }
    }

    sort(res, res+cnt);
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++) cout << res[i] << endl;

    return 0;
}
