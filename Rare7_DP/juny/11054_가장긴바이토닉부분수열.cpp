#include <iostream>
using namespace std;

#define endl '\n'
#define MAX 1001

int N, res = 0;
int arr[MAX];
int dp1[MAX], dp2[MAX];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    for(int i = 0; i < N; i++) dp1[i] = dp2[i] = 1;

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dp1[i] <= dp1[j]) dp1[i] = dp1[j] + 1;
        }
    }

    for(int i = N-2; i >= 0; i--) {
        for(int j = N-1; j > i; j--) {
            if(arr[i] > arr[j] && dp2[i] <= dp2[j]) dp2[i] = dp2[j] + 1;
        }
    }

    for(int i = 0; i < N; i++) dp1[i] = dp1[i] + dp2[i];

    for(int i = 0; i < N; i++) {
        if(res < dp1[i]) res = dp1[i];
    }

    cout << res-1 << endl;

    return 0;
}