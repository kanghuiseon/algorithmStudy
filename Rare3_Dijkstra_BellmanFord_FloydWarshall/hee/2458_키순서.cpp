#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 10000000
using namespace std;
int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    vector<vector<int>> arr(n+1, vector<int>(n+1, MAX));
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
    }
    for(int k=1; k<n+1; k++){
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(arr[i][j] > arr[i][k]+arr[k][j]){
                    arr[i][j] = 3;
                }
            }
        }
    }
    int cnt=0;
    int answer=0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(arr[i][j] != MAX || arr[j][i] != MAX){
                cnt++;
            }
        }
        if(cnt==n-1){
            answer++;
        }
        cnt=0;
    }
    printf("%d\n", answer);
    return 0;
}
