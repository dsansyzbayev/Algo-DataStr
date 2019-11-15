#include <bits/stdc++.h>

using namespace std;

bool isPrime(int k){
    if(k<2) return false;
    for(int i = 2; i*i <= k;++i){
        if(k%i == 0) return false;
    }
    return true;
}

int main(){
    vector <int> a;
    int p[1000000];
    int n;
    cin>>n;
    int k;

    for(int i = 0; i < n; i++){
        cin>>k;
        if(isPrime(k)) 
            a.push_back(k);
    }

    for(int i = 0; i <= a.size() - 1; i++){
        cout << a[i] << " ";
    }

    return 0;
}