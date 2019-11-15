#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
        if(!s.length() && !t.length()) return true;
        if(s.length()!=t.length()) return false;
        vector<int> sv(26,0), tv(26,0);
        for(int i=0;i<s.length();i++){
            sv[s[i]-'a']++;
            tv[t[i]-'a']++;
            
        }
        for(int i=0;i<26;i++)
            if(sv[i]!=tv[i]) return false;
        return true;
}

int main(){

    string n, k;
    
    cin >> n >> k;
    cout << isAnagram(n,k);
    return 0;
}

