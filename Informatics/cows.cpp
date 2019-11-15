#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,cows;
    cin>>n>>cows;
    int s[n];
    vector <int> a;

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    for(int j = 0; j < n; j++){
        for(int i =0; i < n; i++){
            a.push_back(abs(s[i] - s[j]));
        }
    }
    sort(a.begin(),a.end());

    int l = 0;
    int r = n-1;
    int res = 0;
    while(l <= r ){
        int m = (l+r)/2;
        if((a[m]*n)/(cows-1) <= abs(a[n-1] - a[0])/(cows-1)){
            res = (a[m]*n)/(cows-1);
            r = m +1;
        } else {
            l = m;
        }
    }

    cout << res;

    return 0;
}



