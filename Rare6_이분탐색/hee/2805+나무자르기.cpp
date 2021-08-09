#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#define MAX_INDEX 1000004
using namespace std;
int n, m;
vector<long long int> arr(MAX_INDEX);
long long int answer = 0;
long long int binarySearch(long long int s, long long int e){
    if(s > e){
        return answer;
    }
    long long int mid = (s+e)/2;
    long long int cutting = 0;
    for(int i=0; i<n; i++){
        if(mid >= arr[i]){
            break;
        }
        cutting += arr[i] - mid;
    }
    
    if(cutting >= m){
        answer = answer > mid ? answer : mid;
    }
    if(cutting > m){
        binarySearch(mid+1, e);
    }
    else{
        binarySearch(s, mid-1);
    }
    return mid;
}
int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    //
    sort(arr.rbegin(), arr.rend());
    binarySearch(0, arr[0]);
    printf("%lld\n", answer);
    return 0;
}

