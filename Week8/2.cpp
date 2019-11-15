#include <iostream>
#include<vector>

using namespace std;

vector<int> prefix_function (string s) 
{
    int n =  s.length();
    vector<int> pi(n); // в i-м элементе (его индекс i-1) количество совпавших символов в начале и конце для подстроки длины i. 
    // p[0]=0 всегда, p[1]=1, если начинается с двух одинаковых 
    for (int i=1; i<n; ++i) 
    {
       // ищем, какой префикс-суффикс можно расширить
        int j = pi[i-1]; // длина предыдущего префикса-суффикса, возможно нулевая
        while ((j > 0) && (s[i] != s[j])) // этот нельзя расширить,
            j = pi[j-1];   // берем длину меньшего префикса-суффикса

        if (s[i] == s[j]) 
            ++j;  // расширяем найденный (возможно пустой) префикс-суффикс
        pi[i] = j;
     }
     return pi;
}

int main(){

string s;
cin >> s;

vector<int> v = prefix_function(s);

for(int i =0; i<v.size(); i++){
 cout << v[i] << " ";
}




 return 0;
}