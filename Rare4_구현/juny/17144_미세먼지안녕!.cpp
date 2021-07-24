#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"
#define MAX 51

int R, C, T;
pair<int,int> map[MAX][MAX]; // first: 현재 미세먼지 양, second: 1초 뒤 추가될 미세먼지 양
pair<int,int> airCleaner = make_pair(-10, -10);
//int up = -1, down = -1;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void init() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(map[i][j].first == -1) map[i][j].second = -1;
            else map[i][j].second = 0;
        }
    }
}

void spread() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            // 확산될 미세먼지가 없거나, 공기청정기가 설치된 곳은 넘어간다.
            if(map[i][j].first <= 0) continue;

            int dust = map[i][j].first;
            int nextDust = map[i][j].first/5; // 다음 칸으로 확산될 먼지 양
            int cnt = 0; // 확산 된 칸 수

            for(int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue; // 배열 밖
                if(map[nx][ny].first == -1) continue; // 공기청정기

                map[nx][ny].second += nextDust; // 추가될 미세먼지
                cnt++;
            }

            map[i][j].first = dust - (nextDust * cnt); // 현재 미세먼지 갱신
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(map[i][j].first == -1) continue;
            map[i][j].first += map[i][j].second;
            map[i][j].second = 0;
        }
    }
}

void cleaning() {
    int up = airCleaner.first; // 반시계방향
    int down = airCleaner.second; // 시계방향
    pair<int,int> tmp = make_pair(0,0);

    int x = up-1, y = 0, go = -1;
    for(int i = 0; i < up-1; i++) {
        map[x][y] = map[x-1][y];
        x += go;
    }

    x = 0, y = 0, go = 1;
    for(int i = 0; i < C; i++) {
        map[x][y] = map[x][y+1];
        y += go;
    }

    x = 0, y = C-1, go = 1;
    for(int i = 0; i < up; i++) {
        map[x][y] = map[x+1][y];
        x += go;
    }

    x = up, y = C-1, go = -1;
    for(int i = 0; i < C-1; i++) {
        map[x][y] = map[x][y-1];
        y += go;
    }
    map[up][1] = make_pair(0,0);

    x = down+1, y = 0, go = 1;
    for(int i = 0; i < R-down-1; i++) {
        map[x][y] = map[x+1][y];
        x += go;
    }

    x = R-1, y = 0, go = 1;
    for(int i = 0; i < C; i++) {
        map[x][y] = map[x][y+1];
        y += go;
    }

    x = R-1, y = C-1, go = -1;
    for(int i = 0; i < R-down-1; i++) {
        map[x][y] = map[x-1][y];
        x += go;
    }

    x = down, y = C-1, go = -1;
    for(int i = 0; i < C-1; i++) {
        map[x][y] = map[x][y-1];
        y += go;
    }
    map[down][1] = make_pair(0,0);

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> map[i][j].first;
            map[i][j].second = 0;
            if(map[i][j].first == -1 ) {
                if(airCleaner.first == -10) airCleaner.first = i;
                else airCleaner.second = i;
                map[i][j].second = -1;
            }
        }
    }

    while(T--) {
        spread();
        cleaning();
    }

    int sum = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(map[i][j].first == -1) continue;
            sum += map[i][j].first;
        }
    }

    cout << sum << endl;

    return 0;
}