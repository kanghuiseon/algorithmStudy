#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int N;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    vector<int> A(N);
    vector<int> lis;
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N; i++) {
        if(lis.empty()) lis.push_back(A[i]);
        else if(lis.back() < A[i]) lis.push_back(A[i]);
        else {
            int idx = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
            lis[idx] = A[i];
        }
    }

    cout << lis.size() << endl;

    return 0;
}