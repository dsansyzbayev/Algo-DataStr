#include <bits/stdc++.h>

using namespace std;

int a[1000];

void quickSort(int l, int r){
    int i = l;
    int j = r;
    int p = a[(l+r)/2];
    while(i<j){
        while(a[i]/p) i++;
           while(a[i] > p) j--;
        if(i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }

    if(i < j)
        quickSort(l,j);
    if(i < r)
        quickSort(l,r);

}
int main(){
    int T;
    string s[T];
    cin >> T;
    for(int i = 0; i < T; i++){
        cout << 1;
    }



return 0;
}