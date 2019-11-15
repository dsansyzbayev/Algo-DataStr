#include <bits/stdc++.h>

using namespace std;

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

int main(){
    string text, pat;
    cin >> text >> pat;
    vector <int> pi = prefix_function(pat);
    int n = text.length();
    int m = pat.length();
    int i =0;
    int j =0;
    while(i < n){
        if(text[i] == pat[j]){
            i++;
            j++;
        }
        if(j == m){
            cout << i-j << " ";
            j = pi[j-1];
        } else {
            if(i < n && text[i] != pat[j]){
                if(j > 0){
                    j = pi[j-1];
                } else i++;
            }
        }
    }
    return 0;
}