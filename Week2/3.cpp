#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > q;
int n,m,x,y,row,col;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>> a[i][j];

    cin >> row >> col;

    a[row][col] = 2;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int r = cur.first;
        int c = cur.second;
        
    }
}