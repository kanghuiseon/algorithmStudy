#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int answer = 0;
vector<int> check(15,0);

void dfs(int index){
    if(index == n){
        answer++;
        return;
    }
    for(int i=0; i<n; i++){
        check[index] = i;
        int j;
        for(j=0; j<index; j++){
            if(check[index] == check[j] || abs(index-j) == abs(check[index]-check[j]))
                break;
        }
        if(j==index)
            dfs(index+1);
    }
}
int main(){
    cin >> n;
    dfs(0);
    printf("%d\n", answer);
    return 0;
}
