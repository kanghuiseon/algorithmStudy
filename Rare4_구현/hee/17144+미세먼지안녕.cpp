#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#define MAX_INDEX 52

using namespace std;
int arr[MAX_INDEX][MAX_INDEX];
int mise[MAX_INDEX][MAX_INDEX];
int tmp[MAX_INDEX][MAX_INDEX];
// 0: 왼, 1: 오, 2: 위, 3: 아래
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int r, c;
void upMise(pair<int, int> up){
    int dir = 1;
    int curX = up.first;
    int curY = up.second+1;
    tmp[curX][curY] = 0;
    tmp[up.first][up.second] = -1;
    while(true){
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if(nx==up.first && ny==up.second){
            break;
        }
        // 오른쪽 끝 도달
        if(ny == c && nx==up.first){
            dir = 2;
        }
        // 가장 오른쪽 위 도달
        else if(nx==1 && ny==c){
            dir = 0;
        }
        // 왼쪽 위 도달
        else if(nx == 1 && ny==up.second){
            dir = 3;
        }
        tmp[nx][ny] = arr[curX][curY];
        curX = nx; curY = ny;
    }
}

void downMise(pair<int, int> down){
    int dir = 1;
    int curX = down.first;
    int curY = down.second+1;
    tmp[curX][curY] = 0;
    tmp[down.first][down.second] = -1;
    while(true){
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if(nx==down.first && ny==down.second){
            break;
        }
        //오른쪽 끝 도달
        if(ny==c && nx==down.first){
            dir = 3;
        }
        //맨 아래 오른쪽 끝
        else if(nx==r && ny==c){
            dir=0;
        }
        // 공청 맨 아래쪽 도달
        else if(nx==r && ny==down.second){
            dir=2;
        }
        tmp[nx][ny] = arr[curX][curY];
        curX = nx; curY = ny;
    }
}
int main(){
    int t;
    scanf("%d %d %d", &r, &c, &t);
    pair<int, int> up;
    pair<int, int> down;
    bool flag = true;
    
    for(int i=1; i<r+1; i++){
        for(int j=1; j<c+1; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == -1){
                if(flag){
                    flag = false;
                    up.first = i;
                    up.second = j;
                }
                else{
                    down.first = i;
                    down.second = j;
                }
            }
        }
    }
    
    while(t--){
        for(int i=1; i<r+1; i++){
            for(int j=1; j<c+1; j++){
                //만약 미세먼지라면
                if(arr[i][j] != 0 && arr[i][j] != -1){
                    int cnt = 4;
                    // 양 사방 다 보기
                    for(int k=0; k<4; k++){
                        int nr = i + dx[k];
                        int nc = j + dy[k];
                        if(nr <= 0 || nr > r || nc <= 0 || nc > c || arr[nr][nc] == -1){
                            cnt--;
                            continue;
                        }
                    }
                    mise[i][j] += arr[i][j] - ((arr[i][j]/5)*cnt);
                    for(int k=0; k<4; k++){
                        int nr = i + dx[k];
                        int nc = j + dy[k];
                        if(nr <= 0 || nr > r || nc <= 0 || nc > c ||  arr[nr][nc] == -1){
                            continue;
                        }
                        mise[nr][nc] += arr[i][j]/5;
                    }
                }
            }
        }
        for(int i=1; i<r+1; i++){
            for(int j=1; j<c+1; j++){
                arr[i][j] = mise[i][j];
            }
        }
        for(int i=1; i<r+1; i++){
            for(int j=1; j<c+1; j++){
                tmp[i][j] = arr[i][j];
            }
        }
        upMise(up);
        downMise(down);
        for(int i=1; i<r+1; i++){
            for(int j=1; j<c+1; j++){
                arr[i][j] = tmp[i][j];
            }
        }
        for(int i=1; i<r+1; i++){
            for(int j=1; j<c+1; j++){
                mise[i][j] = 0;
            }
        }
    }
    int sum=0;
    for(int i=1; i<r+1; i++){
        for(int j=1; j<c+1; j++){
            if(arr[i][j] == -1){
                continue;
            }
            sum += arr[i][j];
        }
    }
    printf("%d\n", sum);
    return 0;
}
