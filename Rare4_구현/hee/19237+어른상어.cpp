#include <iostream>
#include <string>
#include <vector>

#define MAX_INDEX 22
#define MAX_SHARKS 402
using namespace std;
int n, m;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
vector<vector<pair<int, int>>> sharks_smell(MAX_INDEX, vector<pair<int, int>>(MAX_INDEX));
int arr[MAX_INDEX][MAX_INDEX];

typedef struct shark{
    int dir;
    bool isAlive;
    int x;
    int y;
    int priority[5][4];
}Shark;

Shark sharks[MAX_SHARKS];

bool checkIsOneOnly(){
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(arr[i][j] != 0 && arr[i][j] != 1){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            int a;
            scanf("%d", &a);
            arr[i][j] = a;
            if(a != 0){
                sharks[a].x = i;
                sharks[a].y = j;
                sharks[a].isAlive = true;
                sharks_smell[i][j] = make_pair(a, k);
            }
        }
    }
    
    for(int i=1; i<m+1; i++){
        scanf("%d", &sharks[i].dir);
    }
    for(int i=1; i<m+1; i++){
        for(int j=1; j<5; j++){
            for(int k=0; k<4; k++){
                cin >> sharks[i].priority[j][k];
            }
        }
    }

    int t=0;
    // 현재 시간
    while(t<=1000){
        //만약 1 상어만 남으면 프린트
        if(checkIsOneOnly()){
            printf("%d\n", t);
            return 0;
        }
        t++;
        for(int i=1; i<MAX_SHARKS; i++){
            //옮길곳 찾았나 못찾았나
            bool flag = false;
            int cx = sharks[i].x;
            int cy = sharks[i].y;
            int dir = sharks[i].dir;
            if(sharks[i].isAlive){
                for(int j=0; j<4; j++){
                    int pdir = sharks[i].priority[dir][j];
                    int nx = cx + dx[pdir];
                    int ny = cy + dy[pdir];
                    // 범위를 벗어나면, 어떤 상어의 냄새가 있다면
                    if(nx < 1 || nx > n || ny < 1 || ny > n || sharks_smell[nx][ny].first != 0){
                        continue;
                    }
                    //이미 움직인 상어가 있으면
                    if(arr[nx][ny] != 0){
                        // 근데 나보다 숫자가 크면
                        if(i < arr[nx][ny]){
                            sharks[arr[nx][ny]].isAlive = false;
                            arr[cx][cy] = 0;
                            arr[nx][ny] = i;
                            sharks[i].x = nx;
                            sharks[i].y = ny;
                            sharks[i].dir = pdir;
                            flag = true;
                        }
                        // 작으면, 나 자신 죽이기
                        else{
                            arr[cx][cy] = 0;
                            sharks[i].isAlive = false;
                            flag = true;
                            break;
                        }
                    }
                    // 아무 상어가 없으면
                    else{
                        sharks[i].x = nx;
                        sharks[i].y = ny;
                        sharks[i].dir = pdir;
                        arr[cx][cy] = 0;
                        arr[nx][ny] = i;
                        flag = true;
                    }
                    break;
                }
                
                // 만약 이동할 곳이 없으면 자기 자신의 냄새로 돌아가기
                if(!flag){
                    for(int j=0; j<4; j++){
                        int pdir = sharks[i].priority[dir][j];
                        int nx = cx + dx[pdir];
                        int ny = cy + dy[pdir];
                        
                        if(nx < 1 || nx > n || ny < 1 || ny > n){
                            continue;
                        }
                        if(sharks_smell[nx][ny].first == i){
                            arr[cx][cy] = 0;
                            arr[nx][ny] = i;
                            sharks[i].x = nx;
                            sharks[i].y = ny;
                            sharks[i].dir = pdir;
                            break;
                        }
                    }
                }
            }
            
            
        }
        // 현재 위치에 새로 냄새 남기기
        for(int i=1; i<MAX_SHARKS; i++){
            if(sharks[i].isAlive){
                int x = sharks[i].x;
                int y = sharks[i].y;
                sharks_smell[x][y].first = i;
                sharks_smell[x][y].second = k;
            }
        }
        // 다른 곳에 냄새 1씩 제거
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(arr[i][j] == 0 && sharks_smell[i][j].second > 0){
                    sharks_smell[i][j].second -= 1;
                    if(sharks_smell[i][j].second == 0){
                        sharks_smell[i][j].first = 0;
                    }
                }
            }
        }
        
    }
    printf("-1\n");
    return 0;
}
