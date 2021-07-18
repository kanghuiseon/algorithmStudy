#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int N, K;
string number;
deque<char> dq;

int main() {
    scanf("%d %d", &N, &K);
    cin >> number;

    for(int i = 0; i < N; i++) {
        while(K != 0 && !dq.empty() && dq.back() < number[i]) {
            dq.pop_back();
            K--;
        }
        dq.push_back(number[i]);
    }

    for(int i = 0; i < dq.size() - K; i++) {
        printf("%c", dq[i]);
    }
    printf("\n");

    return 0;
}