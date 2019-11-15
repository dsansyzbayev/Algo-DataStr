#include <iostream>
#include <stack>
#include <bits/stdc++.h> 

using namespace std;

int main() {
    string s;
    cin >> s;
    char al [] = "qwertyuiopasdfghjklzxcvbnm";
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j< strlen(al); j++){
        if (st.empty()) {
            st.push(s[i]);
        }
        else {
            if (st.top() == al[j] && s[i] == al[j]) {
                st.pop();
            }
            else st.push(s[i]);
        }
        }
    }
    if (st.empty()) cout << "YES";
    else cout << "NO";
}