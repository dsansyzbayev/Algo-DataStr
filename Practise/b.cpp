#include <iostream>
#include <vector>

using namespace std;
/*
long long p[10010];
long long pref[10010];

void precalc(){
    p[0]=1;
    for(int i=1; i <10001;i++){
        p[i] = p[i-1]*31;
    }
}

void hashCalc(string s){
    for(int i = 0; i < s.size(); i++){
        pref[i]=((s[i]-'a')*p[i]);
        if(i){
            pref[i]+= pref[i-1];
        }
    }
}

long long hashString(string s){
    long long hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash+=((s[i]-'a')*p[i]);
    }
    return hash;
}*/

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  
            ++j;
		pi[i] = j;
	}
	return pi;
}

int main (){
    /*
    precalc();
    string text,pat;
    cin >> text;
    hashCalc(text);
    int T;
    cin >> T;
    int n = text.size();
    for(int t = 0; t < T; t++){
        string sub;
        cin >> sub;
        bool issub = false;
        long long subHash = hashString(sub);
        int cnt = 0;
        int m = sub.size();
        for(int i = 0; i < n-m+1;i++){
            int j = i+m-1;
            long long hashij = pref[j];
            if(i)
                hashij -=pref[i-1];
            if(hashij == subHash*p[i]){
                issub = true;
                break;
            }
        }
        if(issub == true)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }*/

    string text;
    cin >> text;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string sub;
        cin >> sub;
        bool issub = false;
        vector<int> pi = prefix_function(sub+"#"+text);
        for(int j = 0; j < pi.size(); j++){
            if(pi[j] == sub.size()){
                issub = true;
                break;
            }
        }
        if(issub == true){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}