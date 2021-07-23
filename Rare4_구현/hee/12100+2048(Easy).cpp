#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<vector<int>> arr(21, vector<int>(21, 0));
int Max = -1;
int direction[5];
int tmp[21][21];
void down(){
    queue<int> q;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>-1; j--){
            if(arr[j][i] != 0){
                q.push(arr[j][i]);
                arr[j][i] = 0;
            }
        }
        int index = n-1;
        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(arr[index][i] == 0){
                arr[index][i] = num;
            }
            else if(arr[index][i] == num){
                arr[index][i] *= 2;
                index--;
            }
            else{
                arr[--index][i] = num;
            }
        }
    }
}
void up(){
    queue<int> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[j][i] != 0){
                q.push(arr[j][i]);
                arr[j][i] = 0;
            }
        }
        int index = 0;
        while(!q.empty()){
            int num = q.front();
            q.pop();
            
            if(arr[index][i] == 0){
                arr[index][i] = num;
            }
            else if(arr[index][i] == num){
                arr[index][i] *= 2;
                index++;
            }
            else{
                arr[++index][i] = num;
            }
        }
    }
}
void right(){
    queue<int> q;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>-1; j--){
            if(arr[i][j] != 0){
                q.push(arr[i][j]);
                arr[i][j] = 0;
            }
        }
        int index = n-1;
        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(arr[i][index] == 0){
                arr[i][index] = num;
            }
            else if(arr[i][index] == num){
                arr[i][index] *= 2;
                index--;
            }
            else{
                arr[i][--index] = num;
            }
        }
    }
}
void left(){
    queue<int> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] != 0){
                q.push(arr[i][j]);
                arr[i][j] = 0;
            }
        }
        int index=0;
        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(arr[i][index] == 0){
                arr[i][index] = num;
            }
            else if(arr[i][index] == num){
                arr[i][index] *= 2;
                index++;
            }
            else{
                arr[i][++index] = num;
            }
        }
    }
}

void game(){
    for(int i=0; i<5; i++){
        if(direction[i] == 0){
            up();
        }
        else if(direction[i] == 1){
            down();
        }
        else if(direction[i] == 2){
            left();
        }
        else if(direction[i] == 3){
            right();
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Max = max(Max, arr[i][j]);
        }
    }
}
void dfs(int cnt){
    if(cnt == 5){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                tmp[i][j] = arr[i][j];
            }
        }
        game();
        return;
    }
    
    
    for(int i=0; i<4; i++){
        direction[cnt] = i;
        dfs(cnt+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j] = tmp[i][j];
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    dfs(0);
    printf("%d\n", Max);
    return 0;
}
