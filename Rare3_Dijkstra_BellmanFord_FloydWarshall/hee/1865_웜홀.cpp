#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 0x7fffffff
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        // n : 지점의 수, m : 도로의 개수, w : 웜홀의 개수
        int n, m, w;
        scanf("%d %d %d",&n,&m,&w);
        vector<vector<pair<int, int>>> arr(n+1);
        long long int distance[n+1];
        for(int i=1; i<n+1; i++){
            distance[i] = MAX;
        }
        for(int i=0; i<m; i++){
            // s, e : 연결된 지점의 번호, t: 이 도로를 통해 걸리는 시간
            int s, e, t;
            scanf("%d %d %d",&s,&e,&t);
            arr[s].push_back(make_pair(e, t));
            arr[e].push_back(make_pair(s, t));
        }
        for(int i=0; i<w; i++){
            //s, e: 시작, 도착 지점, t: 줄어드는 시간
            int s, e, t;
            scanf("%d %d %d",&s,&e,&t);
            bool f = true;
            for(int i=0; i<arr[s].size(); i++){
                if(arr[s][i].first == e){
                    arr[s][i].second = min(arr[s][i].second, -t);
                    f = false;
                    break;
                }
            }
            if(f){
                arr[s].push_back(make_pair(e, -t));
            }
        }
        for(int i=1; i<n+1; i++){
            for(int node=1; node<n+1; node++){
                for(int j=0; j<arr[node].size(); j++){
                    if(distance[node] + arr[node][j].second < distance[arr[node][j].first]){
                        distance[arr[node][j].first] = distance[node] + arr[node][j].second;
                    }
                }
            }
        }
        bool flag = true;
        for(int node=1; node<n+1; node++){
            for(int j=0; j<arr[node].size(); j++){
                if(distance[node] + arr[node][j].second < distance[arr[node][j].first]){
                    flag = false;
                }
            }
        }
      
        if(!flag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
