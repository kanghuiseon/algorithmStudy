#include <iostream>
#include <vector>
#include <queue>
#define MAX 0x7fffffff
#define MAX_INDEX 51
using namespace std;
int n, m;
int arr[MAX_INDEX][MAX_INDEX];
int Min = 0x7fffffff;
vector<pair<int, int>> chicken;

void dfs(int cnt, int current, vector<vector<int>> dists){
    if(cnt == m){
        int sum = 0;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(dists[i][j] != MAX){
                    sum += dists[i][j];
                }
            }
        }
        Min = min(Min, sum);
        return;
    }
    int tmp[n+1][n+1];
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            tmp[i][j] = dists[i][j];
        }
    }
    for(int c=current; c<chicken.size(); c++){
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(arr[i][j] == 1){
                    int dist = abs(chicken[c].first - i) + abs(chicken[c].second - j);
                    dists[i][j] = min(dists[i][j], dist);
                }
            }
        }
        dfs(cnt+1, c+1, dists);
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                dists[i][j] = tmp[i][j];
            }
        }
    }
}
int main(){
    vector<vector<int>> dists(MAX_INDEX, vector<int>(MAX_INDEX, MAX));
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 2){
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0, 0, dists);
    printf("%d\n", Min);
    return 0;
}
