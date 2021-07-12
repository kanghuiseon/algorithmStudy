#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a, b;
        cin >> a >> b;
        vector<pair<int, int>> com(n+2);
        for(int i=0; i<n; i++){
            cin >> com[i].first >> com[i].second;
        }
        pair<int, int> dest;
        bool check[102] = {false,};
        int c, d;
        cin >> c >> d;
        dest.first = c; dest.second = d;
        com[n].first = c; com[n].second = d;
        queue<pair<int, int>> q;
        q.push(make_pair(a, b));
        bool flag = false;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == dest.first && y == dest.second){
                cout << "happy" << endl;
                flag = true;
                break;
            }
            for(int i=0; i<com.size(); i++){
                if(abs(x-com[i].first)+abs(y-com[i].second) <= 1000 && !check[i]){
                    q.push(make_pair(com[i].first, com[i].second));
                    check[i] = true;
                }
            }
        }
        if(!flag){
            cout << "sad" << endl;
        }
    }
    return 0;
}
