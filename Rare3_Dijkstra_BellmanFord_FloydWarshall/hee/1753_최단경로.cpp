#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 0x7fffffff

using namespace std;
int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    int start;
    scanf("%d", &start);
    vector<vector<pair<int, int>>> arr(v+1);
    //first : w, second : node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(v+1);
    vector<int> check(v+1);
    for(int i=0; i<e; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        arr[u].push_back(make_pair(v, w));
    }
    for(int i=1; i<v+1; i++){
        distance[i] = MAX;
    }
    distance[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(int i = 0; i<arr[node].size(); i++){
            if(distance[arr[node][i].first] > dist + arr[node][i].second){
                distance[arr[node][i].first] = dist + arr[node][i].second;
                pq.push(make_pair(dist + arr[node][i].second, arr[node][i].first));
            }
        }
    }
    
    for(int i = 1; i<v+1; i++){
        if(distance[i] == MAX){
            printf("INF\n");
            continue;
        }
        printf("%d\n", distance[i]);
    }
    return 0;
}


