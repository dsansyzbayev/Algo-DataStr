#include <iostream>
#include <string>

using namespace std;

void compare(string a, string b){
long long uk1=0, uk2=0;

int l= a.length();
while(uk1<l){
    if(a[uk1]==b[uk2]){
    uk1++;
    uk2++;
    }
    else {
    uk1++;
    }
}
cout << a+b.substr(uk2);
}

int main(){

string a,b;
cin >> a >> b;


compare(a,b);


 return 0;
}