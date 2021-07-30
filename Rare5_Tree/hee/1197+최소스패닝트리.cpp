#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#define MAX_INDEX 10002
using namespace std;
int n, m;
int parents[MAX_INDEX];
int sum=0;
int find(int x){
    if(parents[x] == x)
        return x;
    else
        return parents[x] = find(parents[x]);
}
void union_find(int x, int y){
    int xp = find(x);
    int yp = find(y);
    if(xp != yp)
        parents[yp] = xp;
}
bool checkParents(int x, int y){
    int xp = find(x);
    int yp = find(y);
    if(xp == yp){
        return true;
    }
    return false;
}
int main(){
    int v, e;
    scanf("%d %d",&v, &e);
    vector<pair<int, pair<int, int>>> arr;
    for(int i=0; i<e; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr.push_back(make_pair(c, make_pair(a, b)));
    }
    // 최소 정렬
    sort(arr.begin(), arr.end());
    // 자기 자신을 부모로 설정
    for(int i=1; i<v+1; i++){
        parents[i] = i;
    }
    for(int i=0; i<arr.size(); i++){
        // 만약 부모가 다르면 합치고 간선을 더한다.
        if(!checkParents(arr[i].second.first, arr[i].second.second)){
            union_find(arr[i].second.first, arr[i].second.second);
            sum += arr[i].first;
        }
    }
    printf("%d\n", sum);
    
    return 0;
}

