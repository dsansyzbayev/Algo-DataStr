#include <iostream>
#include <set>

using namespace std;

int main(){
    string s,w;
    set<string> a;
    cin >> s;
    int n = s.size();

    for(int i = 0; i < n; i++){
        w ="";
        for(int j = i; j < n; j++){
            w+=s[j];
            a.insert(w);
        }
    }

    set<string> :: iterator it;

    for(it=a.begin(); it!=a.end(); it++){
    cout << *it << " ";
    }

    return 0;
}