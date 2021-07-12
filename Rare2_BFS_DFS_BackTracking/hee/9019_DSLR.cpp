#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int R(int num){
    num = (num%10)*1000 + (num/10);
    return num;
}
int L(int num){
    num = (num/1000) + (num%1000)*10;
    return num;
}
int S(int num){
    num = num==0 ? 9999 : num-1;
    return num;
}
int D(int num){
    num *= 2;
    if(num >= 10000)
        num %= 10000;
    return num;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, target;
        cin >> n >> target;
        bool check[10000] = {false,};
        
        queue<pair<int, string>> q;
        q.push(make_pair(n, ""));
        check[n] = true;
        while(!q.empty()){
            int num = q.front().first;
            string command = q.front().second;
            q.pop();
            if(num == target){
                cout << command << endl;
                break;
            }
            int d = D(num);
            if(!check[d]){
                check[d] = true;
                q.push(make_pair(d, command+"D"));
            }
            int s = S(num);
            if(!check[s]){
                check[s] = true;
                q.push(make_pair(s, command+"S"));
            }
            
            int l = L(num);
            if(!check[l]){
                check[l] = true;
                q.push(make_pair(l, command+"L"));
            }
            
            int r = R(num);
            if(!check[r]){
                check[r] = true;
                q.push(make_pair(r, command+"R"));
            }
        }
    }
    return 0;
}
