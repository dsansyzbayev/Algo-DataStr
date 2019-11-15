#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<char>op;
    stack<int>num;

    string s;
    cin>>s;

    for(int i = 0; i < s.length; i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-'){
            op.push(s[i]);
        } else if(s[i] == '*'){
            op.pop();
        }
    }

    return 0;
}