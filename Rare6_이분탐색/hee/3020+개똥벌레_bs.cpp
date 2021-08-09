#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INDEX 500004
using namespace std;
int n, h;
vector<int> suk;
vector<int> jong;
int main(){
    int Min = 0x7fffffff;
    int cnt = 0;
    scanf("%d %d", &n, &h);
    for(int i=0; i<n/2; i++){
        int s, j;
        cin >> s >> j;
        suk.push_back(s);
        jong.push_back(j);
    }
    sort(suk.begin(), suk.end());
    sort(jong.begin(), jong.end());
    
    for(int i=1; i<=h; i++){
        int idx = lower_bound(suk.begin(), suk.end(), i) - suk.begin();
        idx += lower_bound(jong.begin(), jong.end(), h-i+1) - jong.begin();
        idx = n - idx;
        
        if(idx < Min){
            Min = idx;
            cnt = 1;
        }
        if(idx == Min){
            cnt++;
        }
    }
    printf("%d %d\n", Min, cnt-1);
    return 0;
}
