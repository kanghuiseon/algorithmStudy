#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;
int n;
int arr[22][22];
bool people[20];
int Min = 0x7fffffff;
void dfs(int team, int cnt, int current){
    vector<int> start;
    vector<int> link;
    int sum1=0, sum2=0;
    if(team == cnt){
        for(int i=0; i<n; i++){
            if(people[i]){
                start.push_back(i);
            }
            else{
                link.push_back(i);
            }
        }
        for(int i=0; i<team; i++){
            for(int j=0; j<team; j++){
                sum1 += arr[start[i]][start[j]];
                sum2 += arr[link[i]][link[j]];
            }
        }
        if(Min > abs(sum1-sum2)){
            Min = abs(sum1-sum2);
        }
        return;
    }
    for(int i=current; i<n; i++){
        if(people[i])
            continue;
        people[i] = true;
        dfs(team, cnt+1, i);
        people[i] = false;
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    dfs(n/2, 0,0);
    printf("%d\n", Min);
    return 0;
}

