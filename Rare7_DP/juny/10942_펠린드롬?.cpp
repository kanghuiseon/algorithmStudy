#include <iostream>
using namespace std;

#define endl '\n'
#define MAX 2001

int N, M;
int arr[MAX];
bool palin[MAX][MAX];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    // 길이 1
    for(int i = 1; i <= N; i++) palin[i][i] = true;

    // 길이 2
    for(int i = 1; i < N; i++) {
        if(arr[i] == arr[i+1]) palin[i][i+1] = true;
    }

    // 길이 3 이상
    // i: S와 E 사이의 거리
    for(int i = 2; i < N; i++) {
        for(int j = 1; j <= N-i; j++) {
            if(arr[j] == arr[j+i] && palin[j+1][j+i-1]) palin[j][j+i] = true;
        }
    }

    cin >> M;

    for(int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        cout << palin[S][E] << endl;
    }

    return 0;
}