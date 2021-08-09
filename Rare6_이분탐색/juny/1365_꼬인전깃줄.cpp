#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N), lis;
    for(int i = 0; i < N; i++) cin >> v[i];

    for(int i = 0; i < N; i++) {
        if(lis.empty()) lis.push_back(v[i]);
        else if(lis.back() < v[i]) lis.push_back(v[i]);
        else {
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
        }
    }

    cout << N - lis.size() << endl;

    return 0;
}