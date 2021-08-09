#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int N, H;
vector<int> bottom, top;
int res = 987654321;
int cnt = 0;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> H;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if(!(i%2)) bottom.push_back(tmp);
        else top.push_back(tmp);
    }

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    for(int i = 1; i <= H; i++) {
        int val = lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin();
        val += upper_bound(top.begin(), top.end(), H-i) - top.begin();
        val = N - val;

        if(res == val) cnt++;
        else if(res > val) {
            res = val;
            cnt = 1;
        }
    }

    cout << res << " " << cnt << endl;

    return 0;
}