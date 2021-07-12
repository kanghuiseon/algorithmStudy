#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> arr(20002);
vector<int> check(20002, -1);
int n;
bool bfs(int v){
    queue<int> q;
    q.push(v);
    check[v] = true;
    while(!q.empty()){
        int node = q.front();
        int color = check[node];
        q.pop();
        for(int i=0; i<arr[node].size(); i++){
            if(check[arr[node][i]] == -1){
                check[arr[node][i]] = !color;
                q.push(arr[node][i]);
            }else{
                if(check[arr[node][i]] == check[node]){
                    return false;
                }
            }
        }
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int v, e;
        cin >> v >> e;
        n=v;
        for(int i=0; i<v+1; i++){
            check[i] = -1;
        }
        for(int i=0; i<e; i++){
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        string answer = "";
        for(int j=1; j<v+1; j++){
            if(check[j] == -1){
                if(!bfs(j)){
                    answer = "NO";
                    break;
                }
                else{
                    answer = "YES";
                }
            }
        }
        printf("%s\n", answer.c_str());
        for(int i=0; i<v+1; i++){
            arr[i].clear();
        }
    }
    return 0;
}
