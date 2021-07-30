#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_KEY 255
#define MAX_INDEX 55
using namespace std;
int parents[MAX_KEY];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;
vector<string> arr(MAX_INDEX);
vector<pair<int, int>> copies;
bool check[MAX_INDEX][MAX_INDEX];

int findRoot(int x){
    if(x == parents[x])
        return x;
    return parents[x] = findRoot(parents[x]);
}

void union_find(int x, int y){
    x = findRoot(x);
    y = findRoot(y);
    if(x != y){
        parents[y] = x;
    }
}

bool checkSameArea(int x, int y){
    x = findRoot(x);
    y = findRoot(y);
    if(x == y){
        return true;
    }
    return false;
}


int calDistance(pair<int, int> current, pair<int, int> target){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(current, 0));
    check[current.first][current.second] = true;
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int d = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] == '1' || check[nx][ny]){
                continue;
            }
            if(nx == target.first && ny == target.second){
                return d+1;
            }
            q.push(make_pair(make_pair(nx, ny), d+1));
            check[nx][ny] = true;
        }
    }
    return -1;
}
int main(){
    scanf("%d %d", &n, &m);
    vector<pair<int, pair<int, int>>> mst;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 'S' || arr[i][j] == 'K'){
                copies.push_back(make_pair(i, j));
            }
        }
    }
    for(int i=0; i<copies.size(); i++){
        for(int j=i+1; j<copies.size(); j++){
            int distance = calDistance(copies[i], copies[j]);
            if(distance == -1){
                printf("-1\n");
                return 0;
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    check[i][j] = false;
                }
            }
            mst.push_back(make_pair(distance, make_pair(i, j)));
        }
    }
    for(int i=0; i<copies.size(); i++){
        parents[i] = i;
    }
    sort(mst.begin(), mst.end());
    int sum = 0;
    for(int i=0; i<mst.size(); i++){
        int a = mst[i].second.first;
        int b = mst[i].second.second;
        if(!checkSameArea(a, b)){
            union_find(a, b);
            sum += mst[i].first;
        }
    }
    printf("%d\n", sum);
    return 0;
}



