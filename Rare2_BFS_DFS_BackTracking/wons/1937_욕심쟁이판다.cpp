#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAXN 500

using namespace std;

int N,ans,map[MAXN+1][MAXN+1],visited[MAXN+1][MAXN+1];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

int bfs(int x, int y) {

    queue<pair<pair<int,int>,int> > q; // x,y,L
    q.push(make_pair(make_pair(x,y),1));
    memset(visited,0,sizeof(visited));
    int res = 0;
    while (!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int L = q.front().second;
        res = max(res,L);
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0 <= cx && cx < N && 0 <= cy && cy < N && visited[nx][ny] == 0 && map[nx][ny] > map[cx][cy]) {
                q.push(make_pair(make_pair(nx,ny),L+1));
            }
        }
    }
    return res;
}

int main() {

    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d",&map[i][j]);
        }
    }
    ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans = max(ans,bfs(i,j));
        }
    }
    printf("%d\n",ans);

    return 0;
}