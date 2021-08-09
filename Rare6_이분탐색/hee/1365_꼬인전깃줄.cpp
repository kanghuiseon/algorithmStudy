#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INDEX 100004
int arr[MAX_INDEX];
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> lis;
    
    for(int i=0; i<n; i++){
        if(lis.empty()){
            lis.push_back(arr[i]);
            continue;
        }
        int last = lis.back();
        if(last < arr[i]){
            lis.push_back(arr[i]);
            continue;
        }
        int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        lis[index] = arr[i];
    }
    int s = lis.size();
    printf("%d\n", n-s);
    return 0;
}
