#include <bits/stdc++.h>
using namespace std;
main() {
        string s;
        cin >> s;
        stack <char> st;
        map <char, char> mp;
        mp['{'] = '}';
        mp['['] = ']';
        mp['('] = ')';
        for(int i = 0; i < s.size(); i ++) {
                if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                        st.push(s[i]);
                else {
                        if(st.empty() || (st.size() && s[i] != mp[st.top()])) {
                                puts("NO");
                                return 0;
                        }
                        else
                                st.pop();
                }
        }
        if(!st.size())
        puts("YES");
        else
        puts("NO");
        return 0;
}
