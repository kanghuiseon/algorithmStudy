#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define endl '\n'

int T, k, n;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> k >> n;
        vector< vector<int> > v(4, vector<int>(n));

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < n; j++) cin >> v[i][j];
        }
        vector<int> list1(n*n), list2(n*n);
        int idx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                list1[idx] = v[0][i] + v[1][j];
                list2[idx] = v[2][i] + v[3][j];
                idx++;
            }
        }

        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());

        int min = 987654321, res = 0;
        bool flag = false;
        for(int i = 0; i < n*n; i++) {
            int k2 = k - list1[i];
            int left = 0, right = (n*n)-1;
            while(left <= right) {
                int mid = (left + right) / 2;
                if(min == abs(k2 - list2[mid]) && res > list1[i] + list2[mid])
                    res = list1[i] + list2[mid];
                else if(min > abs(k2 - list2[mid])) {
                    min = abs(k2 - list2[mid]);
                    res = list1[i] + list2[mid];
                }

                if(k2 < list2[mid]) right = mid - 1;
                else if(k2 > list2[mid]) left = mid + 1;
                else {
                    cout << k << endl;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout << res << endl;
    }

    return 0;
}