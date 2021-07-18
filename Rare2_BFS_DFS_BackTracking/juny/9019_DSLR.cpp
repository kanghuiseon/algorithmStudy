#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;
#define MAX 10001

int T;
int A, B;
bool visit[MAX];

int D(int n) { return 2*n <= 9999 ? 2*n : (2*n)%10000; }

int S(int n) { return (n--) != 0 ? n : 9999; }

int L(int n) { return (n%1000)*10 + (n/1000); }

int R(int n) { return (n%10)*1000 + (n/10); }

string bfs(int n) {
    memset(visit, false, sizeof(visit));
    queue< pair< int,string > > q;
    
    q.push(make_pair(A,""));
    visit[A] = true;

    while(!q.empty()) {
        int n = q.front().first;
        string s = q.front().second;
        q.pop();

        if(n == B) return s;

        if(!visit[D(n)]) {
            visit[D(n)] = true;
            q.push(make_pair(D(n),s+"D"));
        }
        if(!visit[S(n)]) {
            visit[S(n)] = true;
            q.push(make_pair(S(n),s+"S"));
        }
        if(!visit[L(n)]) {
            visit[L(n)] = true;
            q.push(make_pair(L(n),s+"L"));
        }
        if(!visit[R(n)]) {
            visit[R(n)] = true;
            q.push(make_pair(R(n),s+"R"));
        }
    }
    return "-1";
}

int main() {
    cin >> T;
    while(T--) {
        cin >> A >> B;
        cout << bfs(A) << endl;

    }
    return 0;
}