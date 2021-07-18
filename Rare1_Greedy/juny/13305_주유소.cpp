#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    vector<long long int> length;
    vector<long long int> price;
    for(int i = 0; i < N-1; i++) {
        long long int tmp;
        scanf("%lld", &tmp);
        length.push_back(tmp);
    }
    for(int i = 0; i < N; i++) {
        long long int tmp;
        scanf("%lld", &tmp);
        price.push_back(tmp);
    }

    long long int cost = 0;
    long long int p = price[0];
    for(int i = 0; i < N-1; i++) {
        if(p > price[i]) p = price[i];
        cost += p*length[i];
    }

    printf("%lld\n", cost);

    return 0;
}