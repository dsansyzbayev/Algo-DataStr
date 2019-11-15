#include <iostream>

using namespace std;

int p[100001];


int main(){
    int n;
    cin>>n;
    //n = 25;
    //i = 2;
    //k = 2;
    for(int i = 2; i * i <=n; i++){
        if(p[i] == 0){
            int k = i;
            while(k + i <= n){
                k+=i;
                p[k] = 1;
            }
        }
    }

    for(int i = 2; i<=n; i++){
        if(p[i] == 0){
            cout<<i<< " ";
        }
    }
    return 0;
}