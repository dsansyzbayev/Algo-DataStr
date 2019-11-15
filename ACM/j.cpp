#include <bits/stdc++.h>

using namespace std;

int main(){
    int pen;
    int apple;
    cin >> pen;
    cin >> apple;

    int lol = 100500;
    int trash = 0;
    int i = 0;
    while(i < lol && apple != min(apple, trash)){
        int j = 0;
        while(j < lol && pen == max(pen,apple)){
            pen = pen - apple;
            j++;
            }
        int pineapple = pen;
        pen = apple;
        apple = pineapple;
        i++;
    }
    cout << apple + pen;
    return 0;
}