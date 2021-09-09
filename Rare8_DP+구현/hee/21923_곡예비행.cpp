#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_INDEX 1000
#define MIN -0x7fffffff
using namespace std;
int scoreUp[MAX_INDEX][MAX_INDEX];
int scoreDown[MAX_INDEX][MAX_INDEX];
int scoreAll[MAX_INDEX][MAX_INDEX];
int n, m;
// 1 = 위, -1 = 아래
// 앞, 위
int dx[2] = {0, -1};
int dy[2] = {1, 0};
int Max = MIN;
void bfs(int x, int y, int flag){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    if(flag == 1){
        scoreUp[x][y] = scoreAll[x][y];
    }
    else if(flag == -1){
        scoreDown[x][y] = scoreAll[x][y];
    }
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<2; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i]*flag;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
            if(flag == 1){
                if(scoreUp[nx][ny] < scoreUp[cx][cy] + scoreAll[nx][ny]){
                    scoreUp[nx][ny] = scoreUp[cx][cy] + scoreAll[nx][ny];
                    q.push(make_pair(nx, ny));
                }
                
            }
            else if(flag == -1){
                if(scoreDown[nx][ny] < scoreDown[cx][cy] + scoreAll[nx][ny]){
                    scoreDown[nx][ny] = scoreDown[cx][cy] + scoreAll[nx][ny];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a;
            scanf("%d", &a);
            scoreAll[i][j] = a;
            scoreUp[i][j] = MIN;
            scoreDown[i][j] = MIN;
        }
    }
    bfs(n-1, 0, 1);
    bfs(n-1, m-1, -1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            Max = max(Max, scoreUp[i][j] + scoreDown[i][j]);
        }
    }
    printf("%d\n", Max);
    return 0;
}

