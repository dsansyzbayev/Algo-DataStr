#include <iostream>

using namespace std;

int g[100][100];

int main(){
    int m,n,x,y;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        g[x][y]=1;
        g[y][x]=1;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}