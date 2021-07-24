#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 51
#define INF 987654321

int N, M;
int map[MAX][MAX];
vector< pair<int,int> > house;
vector< pair<int,int> > chicken;
vector< pair<int,int> > dist;
bool visit[13];
int result = INF;


int ChickenDist(pair<int,int> p1, pair<int,int> p2) {
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

void dfs(int idx, int cnt) {
    if(cnt == M) {
        int sum = 0;
        for(int i = 0; i < house.size(); i++) {
            int dist = INF;
            for(int j = 0; j < chicken.size(); j++) {
                if(visit[j]) dist = min(dist, ChickenDist(house[i],chicken[j]));
            }
            sum += dist;
        }
        result = min(result, sum);
        return;
    }

    if(idx == chicken.size()) return;

    visit[idx] = true;
    dfs(idx+1, cnt+1);
    visit[idx] = false;
    dfs(idx+1,cnt);

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) house.push_back(make_pair(i,j));
            if(map[i][j] == 2) chicken.push_back(make_pair(i,j));
        }
    }

    dfs(0,0);
    cout << result << endl;

    return 0;
}