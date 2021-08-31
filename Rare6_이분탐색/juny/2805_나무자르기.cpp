#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int N, M, res;
vector<long long> v;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    long long left = 0, right = v[N-1];
    while(left <= right) {
        long long sum = 0;
        long long mid = (left + right) / 2; // 절단기 높이
        for(int i = 0; i < N; i++) {
            if((v[i] - mid) > 0) sum += v[i] - mid;
        }
        
        if(sum >= M) { // 절단기 최대 구하기
            if(res < mid) res = mid;
            left = mid + 1;
        }
        else // 자를 통나무 늘리기
            right = mid - 1;
    }

    cout << res << endl;

    return 0;
}