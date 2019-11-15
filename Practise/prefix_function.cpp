#include <iostream>
#include <vector>

using namespace std;

//o(n^3)
/*
vector<int> prefix_function(string s){
    int n = (int)s.length();
    vector<int>pi (n);
    for(int i = 0; i < n; ++i){
        for(int k = 0; k <= i; ++k){
            if(s.substr(0,k) == s.substr(i-k+1,k)){
                pi[i]= k;
            }
        }
    }
    return pi;
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

int main()
{
    string n;
    cin >> n;
    vector<int> pi = prefix_function(n);
    for(int i = 0; i < pi.size(); i++){
        cout << pi[i] << " ";
    }
    return 0;
}