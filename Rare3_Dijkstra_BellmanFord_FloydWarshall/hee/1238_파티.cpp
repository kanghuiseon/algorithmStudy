#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;
int main(){
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    vector<vector<pair<int, int>>> arr(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<int>> distance(n+1, vector<int>(n+1, MAX));
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr[a].push_back(make_pair(b, c));
    }

    int Max = -1;
    for(int i=1; i<n+1; i++){
        distance[i][i] = 0;
        pq.push(make_pair(0, i));
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(int j=0; j<arr[node].size(); j++){
                if(dist + arr[node][j].second < distance[i][arr[node][j].first]){
                    distance[i][arr[node][j].first] = dist + arr[node][j].second;
                    pq.push(make_pair(dist + arr[node][j].second, arr[node][j].first));
                }
            }
        }
    }
    for(int i=1; i<n+1; i++){
        if(i==x)
            continue;
        int sum = distance[i][x] + distance[x][i];
        Max = max(sum, Max);
    }
    printf("%d\n", Max);
    return 0;
}
