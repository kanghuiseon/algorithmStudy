#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N;
    priority_queue<int, vector<int>, greater<int> > m_pos, m_neg, w_pos, w_neg;
    scanf("%d", &N);

    int input;
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        if(input > 0) m_pos.push(input);
        else m_neg.push(abs(input));
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        if(input > 0) w_pos.push(input);
        else w_neg.push(abs(input));
    }

    int result = 0;
    while(!m_pos.empty() && !w_neg.empty()) {
        if(m_pos.top() < w_neg.top()) {
            result++;
            m_pos.pop();
        }
        w_neg.pop();
    }

    while(!m_neg.empty() && !w_pos.empty()) {
        if(m_neg.top() > w_pos.top()) {
            result++;
            w_pos.pop();
        }
        m_neg.pop();
    }

    printf("%d\n", result);

    return 0;
}