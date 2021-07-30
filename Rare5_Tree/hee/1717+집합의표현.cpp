#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_INDEX 1000003
using namespace std;
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
    scanf("%d %d", &n, &m);
    for(int i=1; i<n+1; i++){
        parents[i] = i;
    }
    for(int i=0; i<m; i++){
        int flag, a, b;
        scanf("%d %d %d",&flag, &a, &b);
        // 같냐?
        if(flag){
            if(checkSameArea(a, b)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }else{ // 합쳐라
            union_find(a, b);
        }
    }
    return 0;
}

