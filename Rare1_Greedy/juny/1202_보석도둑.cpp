#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector< pair<int,int> > jewel;
    vector<int> bag;

    int a, b;
    for(int n = 0; n < N; n++) {
        cin >> a >> b;
        jewel.push_back(make_pair(a, b));
    }
    for(int k = 0; k < K; k++) {
        cin >> a;
        bag.push_back(a);
    }

    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    long long sum = 0;
    priority_queue <int> pq;
    int idx = 0;
    for(int k = 0; k < K; k++) {
        while(idx < N && bag[k] >= jewel[idx].first) 
            pq.push(jewel[idx++].second);

        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum << endl;

    return 0;
}