#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_INDEX 9

using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int k, n;
        scanf("%d %d", &k, &n);
        vector<vector<int>> arr(4, vector<int>(n, 0));
        vector<vector<int>> sumArr(2, vector<int>(n*n));
        for(int i=0; i<4; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        int index = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sumArr[0][index] = arr[0][i] + arr[1][j];
                sumArr[1][index] = arr[2][i] + arr[3][j];
                index++;
            }
        }
        sort(sumArr[0].begin(), sumArr[0].end());
        sort(sumArr[1].begin(), sumArr[1].end());
        // tmpDiff: K와 합의 차이, 이게 최소가 되어야 한다. tmpNum: 차이가 최소가 되는 합.
        int tmpDiff=0x7fffffff, tmpNum=0;
        bool flag = false;
        for(int i=0; i<n*n; i++){
            int tmp = k-sumArr[0][i];
            int tmpIndex = lower_bound(sumArr[1].begin(), sumArr[1].end(), tmp) - sumArr[1].begin();
            // 인덱스가 범위 넘어가면 그냥 마지막 인덱스 넣기.
            if(tmpIndex >= n*n)
                tmpIndex -= 1;
            if(tmpIndex > 0){
            //이거는 바로 작은 값
                int diff = abs(tmp-sumArr[1][tmpIndex-1]);
                int diffNum = sumArr[0][i]+sumArr[1][tmpIndex-1];
                if(tmpDiff >= diff){
                    if(tmpDiff > diff || tmpNum > diffNum){
                        tmpDiff = diff;
                        tmpNum = diffNum;
                    }
                }
                //이거는 바로 큰값
                diff = abs(tmp-sumArr[1][tmpIndex]);
                diffNum = sumArr[0][i]+sumArr[1][tmpIndex];
                if(tmpDiff >= diff){
                    if(tmpDiff > diff || tmpNum > diffNum){
                        tmpDiff = diff;
                        tmpNum = diffNum;
                    }
                }
            }
            else{
                int diff = abs(tmp-sumArr[1][tmpIndex]);
                int diffNum = sumArr[0][i]+sumArr[1][tmpIndex];
                if(tmpDiff >= diff){
                    if(tmpDiff > diff || tmpNum > diffNum){
                        tmpDiff = diff;
                        tmpNum = diffNum;
                    }
                }
            }
        }
        if(!flag)
            printf("%d\n", tmpNum);
    }
    return 0;
}


