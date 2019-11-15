#include <iostream>

using namespace std;

int a[1000];
int n;

void quickSort(int l, int r){
    int i = l;
    int j = r;
    int p = a[(l+r)/2];
    while(i < j){
        while(a[i] < p) i++;
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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    quickSort(0,n);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}