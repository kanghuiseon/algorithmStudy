#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101
#define INF 2147483647

int n, m;
int arr[MAX][MAX];
int a, b, c;

int main() {
    //ios_base :: sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            arr[i][j] = INF;
    }

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(arr[i][k] != INF && arr[k][j] != INF) 
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || arr[i][j] == INF) cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}