#include <iostream>
#include <vector>
#include <deque>

#define endl '\n'
#define MAX 101
using namespace std;

int N, K, L;
int map[MAX][MAX];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int turn(int d, char di) {
    if(di == 'D') {
        if(d == 0) return 2;
        if(d == 1) return 3;
        if(d == 2) return 1;
        if(d == 3) return 0;
    }
    if(di == 'L') {
        if(d == 0) return 3;
        if(d == 1) return 2;
        if(d == 2) return 0;
        if(d == 3) return 1;
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        map[a-1][b-1] = 1;
    }

    vector< pair<int,char> > move;
    cin >> L;
    for(int i = 0; i < L; i++) {
        int a; char b;
        cin >> a >> b;
        move.push_back(make_pair(a,b));
    }
    
    deque< pair<int,int> > snake;
    int x = 0; int y = 0; int d = 0;
    snake.push_back(make_pair(x,y));
    map[x][y] = -1;

    int time = 0; int idx = 0;
    while(1) {
        time++;

        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) break;
        if(map[nx][ny] == -1) break;

        if(map[nx][ny] == 0) {
            map[nx][ny] = -1;
            map[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
            snake.push_front(make_pair(nx,ny));
        }
        else if(map[nx][ny] == 1) {
            map[nx][ny] = -1;
            snake.push_front(make_pair(nx,ny));
        }

        if(idx < move.size()) {
            if(time == move[idx].first) {
                if(move[idx].second == 'L') d = turn(d,'L');
                else if(move[idx].second == 'D') d = turn(d,'D');
                idx++;
            }
        }
        x = nx;
        y = ny;
    }

    cout << time << endl;

    return 0;
}