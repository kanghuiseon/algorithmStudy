#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl "\n"
#define MAX 51

int N, delNode, root;
vector<int> tree[MAX];
int leaf[MAX];

int dfs(int x, int del) {
    int cnt = 0;
    if(x == del) return cnt;
    for(int i = 0; i < tree[x].size(); i++) 
        cnt += dfs(tree[x][i], del);
    
    if(cnt == 0) return 1;
    return cnt;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == -1) root = i;
        else tree[tmp].push_back(i);
    }
    cin >> delNode;

    int res = dfs(root, delNode);

    cout << res << endl;

    return 0;
}