// Trie 자료구조 사용해보기

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'

int t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        vector<string> v;
        
        for(int i = 0; i < n; i++) {
            string str;
            cin >> str;
            v.push_back(str);
        }

        sort(v.begin(), v.end());
        bool flag = true;

        for(int i = 0; i < v.size()-1; i++) {
            if(v[i].length() > v[i+1].length()) continue;
            if(v[i] == v[i+1].substr(0,v[i].length())) {
                flag = false;
                break;
            }
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}