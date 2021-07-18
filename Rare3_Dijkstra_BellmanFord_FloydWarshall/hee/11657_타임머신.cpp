#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 0x7fffffff

using namespace std;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<pair<int, int>>> arr(n+1);
    long long int distance[n+1];
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr[a].push_back(make_pair(b, c));
    }
    for(int i=1; i<n+1; i++){
        distance[i] = MAX;
    }
    distance[1] = 0;
    bool flag = true;
    for(int i=1; i<=n; i++){
        for(int node=1; node<n+1; node++){
            for(int j=0; j<arr[node].size(); j++){
                if (distance[node] == MAX) {
                    continue;
                }
                if(distance[node] + arr[node][j].second < distance[arr[node][j].first]){
                    distance[arr[node][j].first] = distance[node] + arr[node][j].second;
                }
            }
        }
    }
    for(int node=1; node<n+1; node++){
        for(int j=0; j<arr[node].size(); j++){
            if (distance[node] == MAX) {
                continue;
            }
            if(distance[node] + arr[node][j].second < distance[arr[node][j].first]){
                flag = false;
            }
        }
    }
    if(!flag){
        printf("-1\n");
        return 0;
    }
        
    for(int i=2; i<n+1; i++){
        if(distance[i] == MAX){
            printf("-1\n");
            continue;
        }
        printf("%lld\n", distance[i]);
    }
    return 0;
}
