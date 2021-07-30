#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_INDEX 500005
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
using namespace std;
int main(){
    vector<pair<int, int>> arr;
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr.push_back(make_pair(a, b));
    }
    for(int i=0; i<n; i++){
        parents[i] = i;
    }
    int cnt = 0;
    for(int i=0; i<arr.size(); i++){
        int a = arr[i].first;
        int b = arr[i].second;
        if(!checkSameArea(a, b)){
            union_find(a, b);
            cnt++;
        }else{
            printf("%d\n", cnt+1);
            return 0;
        }
    }
    printf("0\n");
    
    return 0;
}

