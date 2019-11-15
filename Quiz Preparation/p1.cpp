#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack <char> st1,st2;

    string s;
    cin>>s;

    for(int i = 0; i < s.length()-1; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            st2.push(s[i]);
        } else {
            st1.push(s[i]);
        }
    }
}