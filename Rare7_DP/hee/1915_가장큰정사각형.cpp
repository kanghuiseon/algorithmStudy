#include <iostream>
#include <algorithm>
#include <string>
#define MAX_INDEX 1004
using namespace std;
int dp[MAX_INDEX][MAX_INDEX];
int arr[MAX_INDEX][MAX_INDEX];
int n, m;
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<n+1; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            arr[i][j+1] = s[j]-'0';
        }
    }
    int Max = 0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(arr[i][j] != 0){
                arr[i][j] = min(arr[i-1][j-1], min(arr[i][j-1], arr[i-1][j]))+1;
                Max = max(Max, arr[i][j]);
            }
        }
    }
    printf("%d\n", Max*Max);
    return 0;
}

