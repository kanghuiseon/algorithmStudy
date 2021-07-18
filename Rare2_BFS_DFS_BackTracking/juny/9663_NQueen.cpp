#include <iostream>

using namespace std;

int N, res;
int map[15];

bool check(int idx) {
    for(int i = 0; i < idx; i++) {
        if(map[i] == map[idx] || abs(map[idx] - map[i]) == abs(idx - i)) return false;
    }
    return true;
}

void dfs(int idx) {
    if(idx == N) { res++; return; }

    for(int i = 0; i < N; i++) {
        map[idx] = i;
        if(check(idx)) dfs(idx+1);
    }
}

int main() {
    cin >> N;

    dfs(0);
    cout << res << endl;

    return 0;
}