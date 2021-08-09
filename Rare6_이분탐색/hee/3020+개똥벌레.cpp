#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#define MAX_INDEX 500004
using namespace std;
int n, h;
vector<int> suk(MAX_INDEX);
vector<int> jong(MAX_INDEX);
int main(){
    scanf("%d %d", &n, &h);
    
    for(int i=0; i<n/2; i++){
        int s, j;
        cin >> s >> j;
        suk[s]++;
        jong[j]++;
    }
    
    for(int i=h; i>=1; i--){
        suk[i] += suk[i+1];
        jong[i] += jong[i+1];
    }
    vector<int> sum;
    for(int i=1; i<=h; i++){
        sum.push_back(suk[i]+jong[h-i+1]);
    }
    
    sort(sum.begin(), sum.end());
    
    int cnt = 1;
    int Min = sum[0];
    for(int i=1; i<h; i++){
        if(Min == sum[i]){
            cnt++;
        }
    }
    printf("%d %d\n", Min, cnt);
    return 0;
}

