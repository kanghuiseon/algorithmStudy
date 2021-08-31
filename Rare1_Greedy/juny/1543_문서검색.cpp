#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string S, sub;
    getline(cin, S, '\n');
    getline(cin, sub, '\n');

    if(S.length() < sub.length()) {
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    for(int i = 0; i < S.length() - sub.length() + 1; i++) {
        bool flag = true;
        for(int j = 0; j < sub.length(); j++) {
            if(S[i+j] != sub[j]) { flag = false; break; }
        }
        if(flag) {
            cnt++;
            i += sub.length() - 1;
        }
    }

    cout << cnt << endl;

    return 0;
}