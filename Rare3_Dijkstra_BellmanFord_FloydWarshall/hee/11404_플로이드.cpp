#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10000001
int arr[101][101];
using namespace std;
int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(i!=j)
                arr[i][j] = MAX;
        }
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = min(arr[a][b], c);
    }
    
    for(int k=1; k<n+1; k++){
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(arr[i][k]+arr[k][j] == MAX){
                    arr[i][j] = MAX;
                    continue;
                }
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(arr[i][j] == MAX)
                printf("0 ");
            else{
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
