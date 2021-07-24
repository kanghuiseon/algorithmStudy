#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#define MAX 102
using namespace std;

//0: 빈, 1: 사과, 2: 뱀 몸
int arr[MAX][MAX];
int t=0;
// 오, 왼, 아래, 위
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, char>> dir;
int rotate(int f, char direction){
    if(direction == 'D'){
        switch(f){
            case 0:
                return 2;
            case 1:
                return 3;
            case 2:
                return 1;
            case 3:
                return 0;
        }
    }
    else if(direction == 'L'){
        switch(f){
            case 0:
                return 3;
            case 1:
                return 2;
            case 2:
                return 0;
            case 3:
                return 1;
        }
    }
    return -1;
}
int main(){
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
    }
    int l;
    scanf("%d", &l);
    for(int i=0; i<l; i++){
        int x; char c;
        cin >> x >> c;
        dir.push_back(make_pair(x, c));
    }
    int x=1, y=1;
    pair<int, int> tail = make_pair(x, y);
    pair<int, int> head = make_pair(x, y);
    queue<tuple<int, int, char>> tailDirection;
    int hf = 0;
    int tf = 0;
    int dirIndex = 0;
    while(true){
        // 새로운 방향
        int nx = head.first + dx[hf];
        int ny = head.second + dy[hf];
        if(nx <= 0 || nx > n || ny <= 0 || ny > n || arr[nx][ny] == 2){
            printf("%d\n", t+1);
            break;
        }
        // 사과라면
        if(arr[nx][ny] == 1){
            arr[nx][ny] = 2;
            head.first = nx;
            head.second = ny;
        }
        // 빈곳이면
        else if(arr[nx][ny] == 0){
            arr[tail.first][tail.second] = 0;
            arr[nx][ny] = 2;
            tail.first = tail.first + dx[tf];
            tail.second = tail.second + dy[tf];
            head.first = nx;
            head.second = ny;
        }
        t++;
        if(dirIndex < dir.size()){
            if(t == dir[dirIndex].first){
                if(dir[dirIndex].second == 'D'){
                    hf = rotate(hf, 'D');
                    tailDirection.push(make_tuple(nx, ny,'D'));
                }
                else if(dir[dirIndex].second == 'L'){
                    hf = rotate(hf, 'L');
                    tailDirection.push(make_tuple(nx, ny,'L'));
                }
                dirIndex++;
            }
        }
        if(!tailDirection.empty()){
            if(tail.first == get<0>(tailDirection.front()) && tail.second == get<1>(tailDirection.front())){
                char tmpDir = get<2>(tailDirection.front());
                tf = rotate(tf, tmpDir);
                tailDirection.pop();
            }
        }
    }
    return 0;
}
