#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    int a[n];
    int b[q][2];
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < q; i++){
        for(int j = 0; j < 2; j++){
            cin >> b[i][j];
        }
    }
    
    return 0;
}