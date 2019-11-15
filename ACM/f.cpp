#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,t,x,y,a,b;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        if( t == 1){
            cin >> x >> y;
        } else if(t == 2){
            cin >> a >> b;
        } else if(t == 3){
            cin >> b >> x >> y;
        }
    }
}