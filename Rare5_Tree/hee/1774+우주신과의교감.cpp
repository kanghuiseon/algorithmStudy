#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#define MAX_INDEX 1002
int parents[MAX_INDEX];
using namespace std;
int find(int x){
    if(parents[x] == x){
        return x;
    }
    else{
        return parents[x] = find(parents[x]);
    }
}
void union_find(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        parents[y] = x;
    }
}
bool checkParents(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y){
        return true;
    }
    return false;
}
int main(){
    int n, m;
    vector<pair<double, double>> arr;
    vector<pair<double, pair<int, int>>> spaceDistance;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        double a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    for(int i=1; i<n+1; i++){
        parents[i] = i;
    }
    for(int j=0; j<m; j++){
        int a, b;
        scanf("%d %d", &a, &b);
        union_find(a, b);
    }
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            double distance = hypot(arr[i].first-arr[j].first, arr[i].second-arr[j].second);
            spaceDistance.push_back(make_pair(distance, make_pair(i+1, j+1)));
        }
    }
    double sum = 0.0;
    sort(spaceDistance.begin(), spaceDistance.end());
    for(int i=0; i<spaceDistance.size(); i++){
        if(!checkParents(spaceDistance[i].second.first, spaceDistance[i].second.second)){
            union_find(spaceDistance[i].second.first, spaceDistance[i].second.second);
            sum += spaceDistance[i].first;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << sum << endl;
    return 0;
}

