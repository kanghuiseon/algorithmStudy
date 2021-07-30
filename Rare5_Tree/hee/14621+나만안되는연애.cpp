#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#define MAX_INDEX 1002
using namespace std;
map<pair<int, int>, bool> mm;
int parents[MAX_INDEX];
int find(int x){
    if(x == parents[x])
        return x;
    return parents[x] = find(parents[x]);
}
void union_find(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        parents[y] = x;
    }
}

bool checkParents(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)
        return true;
    return false;
}


int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    char gender[n+1];
    vector<pair<int, pair<int, int>>> arr;
    for(int i=1; i<n+1; i++){
        cin >> gender[i];
    }
    for(int i=0; i<m; i++){
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        arr.push_back(make_pair(d, make_pair(u, v)));
    }
    for(int i=1; i<n+1; i++){
        parents[i] = i;
    }
    sort(arr.begin(), arr.end());
    int sum=0;
    int cnt=0;
    for(int i=0; i<arr.size(); i++){
        char genderA = gender[arr[i].second.first];
        char genderB = gender[arr[i].second.second];
        // 성별이 다른 경우에만 보기
        if(genderA != genderB && !checkParents(arr[i].second.first, arr[i].second.second)){
            union_find(arr[i].second.first, arr[i].second.second);
            sum += arr[i].first;
            cnt++;
        }
    }
    if(cnt == n-1){
        printf("%d\n", sum);
    }
    else{
        printf("-1\n");
    }
    return 0;
}

