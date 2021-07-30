#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#define MAX_INDEX 100005
using namespace std;
int inorder[MAX_INDEX];
int postorder[MAX_INDEX];
int inOrder[MAX_INDEX];
int n;
void findPreOrder(int is, int ie, int ps, int pe){
    if(is > ie || ps > pe)
        return;
    cout << postorder[pe] << ' ';
    findPreOrder(is, inOrder[postorder[pe]]-1, ps, ps+inOrder[postorder[pe]]-is-1);
    findPreOrder(inOrder[postorder[pe]]+1, ie, ps+inOrder[postorder[pe]]-is, pe-1);
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> inorder[i];
        inOrder[inorder[i]] = i;
    }
    for(int i=0; i<n; i++){
        cin >> postorder[i];
    }
    findPreOrder(0, n-1, 0, n-1);
    cout << endl;
    return 0;
}

