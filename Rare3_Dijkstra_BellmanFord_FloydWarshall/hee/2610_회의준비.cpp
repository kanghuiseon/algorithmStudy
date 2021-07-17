#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#define MAX 1000001
using namespace std;
int check[102];
int arr[102][102];
set<int> tmp;
void dfs(int n, int current){
    tmp.insert(current);
    for(int i=1; i<n; i++){
        if(i==current)
            continue;
        if(!check[i] && arr[current][i] == 1){
            check[i] = true;
            dfs(n, i);
        }
    }
}
int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    // 노드 하나인 경우도 체크해줘야함
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            arr[i][j] = MAX;
        }
    }
    for(int i=1; i<n+1; i++){
        arr[i][i] = 1;
    }
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    // 위원회 수 구하기
    int k=0;
    vector<set<int>> temp;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(arr[i][j] == 1 && !check[i]){
                dfs(n+1, i);
                temp.push_back(tmp);
                tmp.clear();
                k++;
            }
        }
    }
    // 플로이드 와샬, 대표 구하기
    for(int k=1; k<n+1; k++){
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(arr[i][j] > arr[i][k]+arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    set<int> rep;
    for(int i=0; i<temp.size(); i++){
        int Max = -1;
        int Min = MAX;
        int tt=0;
        for(auto a: temp[i]){
            for(int j=1; j<n+1; j++){
                if(arr[a][j] != MAX){
                    Max = max(arr[a][j], Max);
                }
            }
            if(Min > Max){
                Min = Max;
                tt = a;
            }
            Max = -1;
        }
        rep.insert(tt);
    }
    printf("%d\n",k);
    for(auto a: rep){
        printf("%d\n", a);
    }
    return 0;
}
