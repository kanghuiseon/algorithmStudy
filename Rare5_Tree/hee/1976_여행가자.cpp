#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_INDEX 204
#define MAX_CITIES 1004
using namespace std;
int arr[MAX_INDEX][MAX_INDEX];
int cities[MAX_CITIES];
int parents[MAX_INDEX];
int findRoot(int x){
    if(x == parents[x]){
        return x;
    }
    return parents[x] = findRoot(parents[x]);
}

void union_find(int x, int y){
    x = findRoot(x);
    y = findRoot(y);
    if(x != y){
        parents[y] = x;
    }
}

bool checkSameArea(int x, int y){
    x = findRoot(x);
    y = findRoot(y);
    if(x == y){
        return true;
    }
    return false;
}


int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<pair<int, int>> mst;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1){
                mst.push_back(make_pair(i, j));
                arr[i][j] = 0;
                arr[j][i] = 0;
            }
        }
    }
    
    for(int i=0; i<m; i++){
        scanf("%d", &cities[i]);
    }
    for(int i=1; i<n+1; i++){
        parents[i] = i;
    }
    for(int i=0; i<mst.size(); i++){
        int a = mst[i].first;
        int b = mst[i].second;
        if(!checkSameArea(a, b)){
            union_find(a, b);
        }
    }
    int i;
    for(i=0; i<m-1; i++){
        if(!checkSameArea(cities[i], cities[i+1])){
            break;
        }
    }
    if(i == m-1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}

