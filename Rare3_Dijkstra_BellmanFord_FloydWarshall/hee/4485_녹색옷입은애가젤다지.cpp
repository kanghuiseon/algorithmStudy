#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 0x7fffffff
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(){
    int n;
    int cnt=1;
    while(true){
        scanf("%d", &n);
        if(n==0)
            break;
        vector<vector<int>> arr(n+1, vector<int>(n+1, 0));
        vector<vector<int>> rupee(n+1, vector<int>(n+1, MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                int a;
                scanf("%d", &a);
                arr[i][j] = a;
            }
        }
        rupee[1][1] = arr[1][1];
        pq.push(make_pair(arr[1][1], make_pair(1, 1)));
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int r = pq.top().first;
            pq.pop();
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 1 || nx > n || ny < 1 || ny > n)
                    continue;
                if(rupee[nx][ny] > r + arr[nx][ny]){
                    rupee[nx][ny] = r + arr[nx][ny];
                    pq.push(make_pair(r+arr[nx][ny], make_pair(nx, ny)));
                }
            }
        }
        printf("Problem %d: %d\n", cnt, rupee[n][n]);
        cnt++;
    }
    return 0;
}
