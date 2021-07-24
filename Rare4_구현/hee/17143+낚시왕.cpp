#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#define MAX_INDEX 102
using namespace std;
// 허수, 위, 아래, 오, 왼
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
int arr[MAX_INDEX][MAX_INDEX];
// 같은 크기의 상어가 없으니까 크기를 key값으로 한 map 생성
map<int, tuple<int, int, int, int>> sharks;
int move(int d){
    switch(d){
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 3;
    }
    return -1;
}
int main(){
    int r, c, m;
    scanf("%d %d %d", &r, &c, &m);
    if(m==0){
        printf("0\n");
        return 0;
    }
    for(int i=0; i<m; i++){
        int rr, cc, s, d, z;
        scanf("%d %d %d %d %d", &rr, &cc, &s, &d, &z);
        if(d==1 || d==2)
            s = s % ((r-1)*2);
        else if(d==3 || d==4)
            s = s % ((c-1)*2);
        sharks[z] = make_tuple(rr, cc, s, d);
        arr[rr][cc] = z;
    }
    int person = 0;
    int sum = 0;
    int tmpC = c;
    while(tmpC--){
        person++;
        for(int i=1; i<r+1; i++){
            // 땅에서 가장 가까운 상어 지우기
            if(arr[i][person] != 0){
                sum += arr[i][person];
                sharks.erase(arr[i][person]);
                arr[i][person] = 0;
                break;
            }
        }
        // 상어 움직이기
        vector<tuple<int, int, int, int, int>> ttmp;
        for(auto a: sharks){
            int pr = get<0>(a.second);
            int pc = get<1>(a.second);
            int ps = get<2>(a.second);
            int d = get<3>(a.second);
            int z = a.first;
            int nr = pr, nc = pc;
            int tmpS = ps;
            while(tmpS != 0){
                tmpS--;
                nr = nr + dx[d];
                nc = nc + dy[d];
                if(nr <= 0 || nr > r || nc <= 0 || nc > c){
                    nr -= dx[d];
                    nc -= dy[d];
                    d = move(d);
                    tmpS++;
                }
            }
            ttmp.push_back(make_tuple(z, nr, nc, ps, d));
            arr[pr][pc] = 0;
        }
        for(int i=0; i<ttmp.size(); i++){
            sharks[get<0>(ttmp[i])] = make_tuple(get<1>(ttmp[i]), get<2>(ttmp[i]), get<3>(ttmp[i]), get<4>(ttmp[i]));
        }
        // 같은 칸에 두개 이상 있으면 크기가 더 큰 상어 선택
        vector<int> tmp;
        for(auto a: sharks){
            int dr = get<0>(a.second);
            int dc = get<1>(a.second);
            int z = a.first;
            if(arr[dr][dc] == 0){
                arr[dr][dc] = z;
            }
            else{
                if(arr[dr][dc] < z){
                    tmp.push_back(arr[dr][dc]);
                    arr[dr][dc] = z;
                }
            }
        }
        for(int t=0; t<tmp.size(); t++){
            sharks.erase(tmp[t]);
        }
    }
    printf("%d\n", sum);
    return 0;
}
