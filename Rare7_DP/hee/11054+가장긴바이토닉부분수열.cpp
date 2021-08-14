#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INDEX 1004
using namespace std;
int dp[MAX_INDEX];
int dp2[MAX_INDEX];
int arr[MAX_INDEX];
int n;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        dp[i] = 1;
        dp2[i] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] < arr[j]){
                if(dp[j] < dp[i] + 1){
                    dp[j] = dp[i] + 1;
                }
            }
        }
    }
    
    for(int i=n-1; i>=0; i--){
        for(int j=i-1; j>= 0; j--){
            if(arr[i] < arr[j]){
                if(dp2[j] < dp2[i] + 1){
                    dp2[j] = dp2[i] + 1;
                }
            }
        }
    }
    int Max = -1;
    for(int i=0; i<n; i++){
        Max = max(Max, dp[i] + dp2[i]);
    }
    
    printf("%d\n", Max-1);
    return 0;
}

