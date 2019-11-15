#include <bits/stdc++.h>

using namespace std;

int main(){

int n,q;
cin >> n;
int pil[n];
int cnt;


for(int i = 0; i<n; i++){
    cin >> pil[i];
}

cin >> q;

for(int i =0; i<q; i++){
 int L,R;
  cin >> L >> R;
  cnt = 0;
  int b = pil[L];
 for(int i = L; i<=R; i++){
   if(pil[i] > b){
    b = pil[i];
    cnt++;
   } 
 }

 cnt++;
 cout << cnt << endl;
}
 


 return 0;
}
