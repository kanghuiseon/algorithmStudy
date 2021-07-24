#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX_INDEX 32

using namespace std;
int n, m, h;
int Min = 0x7fffffff;
int arr[MAX_INDEX][MAX_INDEX];
bool check(){
    for(int i=1; i<n+1; i++){
        int ans=i;
        for(int j=1; j<h+1; j++){
            if(arr[j][ans] == 1){
                ans++;
            }
            else if(arr[j][ans-1]){
                ans--;
            }
        }
        if(ans != i)
            return false;
    }
    return true;
}
void dfs(int current, int cnt){
    if(cnt > 3)
        return;
    if(check()){
        Min = min(Min, cnt);
        return;
    }
    for(int i=current; i<h+1; i++){
        for(int j=1; j<n+1; j++){
            // 겹치면 안됨!
            if(arr[i][j] || arr[i][j-1]){
                continue;
            }
            arr[i][j] = 1;
            dfs(i, cnt+1);
            arr[i][j] = 0;
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &h);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
    }
    dfs(1, 0);
    if(Min == 0x7fffffff){
        printf("-1\n");
    }
    else{
        printf("%d\n",Min);
    }
    return 0;
}
