#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#define MAX_INDEX 52
using namespace std;
int parents[MAX_INDEX];
int leafs[MAX_INDEX];
int n, removedN;
int cnt=0;
// 제거할 노드가 root이면 true
bool checkRoot(int x){
    if(x == removedN){
        return true;
    }
    else if(x == parents[x]){
        return false;
    }
    else if(x == -2){
        return true;
    }
    return checkRoot(parents[x]);
}
bool checkLeaf(int x){
    if(parents[x] == x){
        return false;
    }
    else if(parents[x] != -2){
        return leafs[parents[x]] += checkLeaf(parents[x]) + 1;
    }
    else{
        leafs[x] = -2;
        return false;
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        if(x == -1){
            parents[i] = i;
        }else{
            parents[i] = x;
        }
    }
    scanf("%d", &removedN);
    for(int i=0; i<n; i++){
        if(checkRoot(i) || i == removedN){
            parents[i] = -2;
        }
    }
    for(int i=0; i<n; i++){
        if(checkLeaf(i)){
        }
    }
    for(int i=0; i<n; i++){
        if(leafs[i] == 0){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    
    return 0;
}

