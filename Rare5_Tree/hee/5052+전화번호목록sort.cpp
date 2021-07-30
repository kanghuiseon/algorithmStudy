#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX_INDEX 0x7fffffff
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        vector<string> arr;
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            string a;
            cin >> a;
            arr.push_back(a);
        }
        sort(arr.begin(), arr.end());
        bool flag = true;
        for(int i=0; i<arr.size()-1; i++){
            int c = arr[i].size();
            int nn = arr[i+1].size();
            if(c >= nn){
                continue;
            }
            if(arr[i+1].substr(0,c) == arr[i]){
                flag = false;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

