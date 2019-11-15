#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int maxi = 0;
map<string,int> M;

vector<int> kmp(string s){
    int m = s.size();
    vector<int> pi(m);
    for(int i =1; i<m; i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j = pi[j-1];
    }
    if(s[i]==s[j]) j++;
    pi[i] = j;
    }
    return pi;
}

void calcMax(string s, string t){
    int n = s.size();
    int m = t.size();
    int i =0 ;
    int j =0;
    int cnt = 0;
    vector<int> pref = kmp(t);
    while(i<n){
        if(s[i]==t[j]){
        i++;
        j++;
    }

    if(j==m){
    cnt++;
    j = pref[j-1];
    }else {
        if(i<n && s[i]!=t[j]){
        if(j>0) j=pref[j-1];
        else i++;
        }
    }
    }  

    M.insert(pair<string,int>(t,cnt));
 
     if(cnt>maxi) maxi = cnt;
}

int main(){

    int n;
    cin >> n;
    vector<string> strings;

    for(int i =0; i<n; i++){
        string s;
        cin >> s;
        strings.push_back(s);
    }

    string t;
    cin >> t;

    for(int i =0; i<strings.size(); i++){
        calcMax(t,strings[i]);
    }

    cout << maxi << endl;

    map<string,int> :: iterator it;

    for(it=M.begin(); it!=M.end(); it++){
        if((*it).second==maxi)
        cout << (*it).first << endl;
    }

    return 0;
}