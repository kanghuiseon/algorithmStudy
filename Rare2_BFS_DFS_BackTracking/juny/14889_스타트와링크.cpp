#include <iostream>
#include <vector>

using namespace std;
#define MAX 21

int N, res = 2147483647;
int arr[MAX][MAX];
bool check[MAX];

void dfs(int idx, int cnt) {
    vector<int> start;
    vector<int> link;
    int s_score = 0;
    int l_score = 0;

    if(cnt == N/2) {
        for(int i = 0; i < N; i++) {
            if(check[i]) start.push_back(i);
            else link.push_back(i);
        }

        for(int i = 0; i < start.size(); i++) {
            for(int j = 0; j < link.size(); j++) {
                s_score += arr[start[i]][start[j]];
                l_score += arr[link[i]][link[j]];
            }
        }

        res = min(res, abs(s_score-l_score));
        return;
    }

    for(int i = idx+1; i < N; i++) {
        if(check[i]) continue;
        check[i] = true;
        dfs(i,cnt+1);
        check[i] = false;
    }

}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    dfs(0,0);
    cout << res << endl;

    return 0;
}