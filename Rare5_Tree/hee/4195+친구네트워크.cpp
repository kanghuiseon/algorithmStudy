#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#define MAX_INDEX 300000
using namespace std;
int parents[MAX_INDEX];
int leafs[MAX_INDEX];
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
        leafs[x] += leafs[y];
        parents[y] = x;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        vector<pair<string, string>> friends;
        map<string, int> mm;
        scanf("%d", &n);
        int cnt=0;
        for(int i=0; i<n; i++){
            string a, b;
            cin >> a >> b;
            friends.push_back(make_pair(a, b));
            if(mm.find(a) == mm.end())
                mm[a] = cnt++;
            if(mm.find(b) == mm.end())
                mm[b] = cnt++;
        }
        for(int i=0; i<n*2+1; i++){
            parents[i] = i;
            leafs[i] = 1;
        }
        for(int i=0; i<friends.size(); i++){
            string a = friends[i].first;
            string b = friends[i].second;
            union_find(mm[a], mm[b]);
            int root = findRoot(mm[a]);
            int leafNum = leafs[root];
            printf("%d\n",leafNum);
        }
    }
    return 0;
}

