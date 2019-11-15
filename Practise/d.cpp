#include <iostream>
#include <vector>

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
    string s,t;
    cin >>s >>t;
    vector<int> p1 = prefix_function(t+s);
    vector<int> p2 = prefix_function(s+t);
    cout << max(p1[p1.size()-1], p2[p2.size()-1]);
    return 0;
}