#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAXN 20

using namespace std;

int R,C,ans,board[MAXN+1][MAXN+1],visited[26];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
char c;

void dfs(int x, int y, int L) {
    ans = max(ans,L);
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < R && 0 <= ny && ny < C && visited[board[nx][ny]] == 0 ){
            visited[board[nx][ny]] = 1;
            dfs(nx,ny,L+1);
            visited[board[nx][ny]] = 0;
        }
    }

}

int main() {

    scanf("%d %d",&R,&C);
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            scanf("%1s",&c);
            board[i][j] = c - 'A';
        }
    }
    memset(visited,0,sizeof(visited));

    ans = 1;
    visited[board[0][0]] = 1;
    dfs(0,0,1);
    printf("%d\n",ans);
    return 0;
}