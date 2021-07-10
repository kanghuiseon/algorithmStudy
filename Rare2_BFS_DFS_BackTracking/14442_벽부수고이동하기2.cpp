#include <stdio.h>
#include <queue>
#include <string.h>
#define MAXN 1000

using namespace std;

int N,M,K;
int board[MAXN+1][MAXN+1],visited[MAXN+1][MAXN+1][11];
int dx[4] = {-1,1,0,0} , dy[4] = {0,0,-1,1};

int bfs() {
    queue<pair<pair<int,int>,int> > q; // x,y,B
    q.push(make_pair(make_pair(0,0),K));
    visited[0][0][K] = 1;

    while (!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int B = q.front().second;
        q.pop();
        if(cx == N-1 && cy == M-1) return visited[cx][cy][B];
        
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M){
                if(visited[nx][ny][B]) continue;
                if(board[nx][ny] == 0) {
                    visited[nx][ny][B] = visited[cx][cy][B] + 1;
                    q.push(make_pair(make_pair(nx,ny),B));
                }
                else if(board[nx][ny] == 1 && B) {
                    visited[nx][ny][B-1] = visited[cx][cy][B] + 1;
                    q.push(make_pair(make_pair(nx,ny),B-1));
                }
            }
        }
    }
    return -1;
}

int main() {

    scanf("%d %d %d",&N,&M,&K);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d",&board[i][j]);
        }
    }
    memset(visited,0,sizeof(visited));
    printf("%d\n",bfs());

    return 0;
}