#include <bits/stdc++.h>

using namespace std;

int main(){

    priority_queue <int, vector<int>, greater<int> > pq;
    string command;
    int n,k;
    cin >> n >> k;
    long long sum = 0;
    for( int i =0; i < n; i++){
        cin >> command;
        if(command == "print"){
            sum = 0;
            priority_queue <int, vector<int>, greater<int> > temp = pq;
            while(!temp.empty()) {
                sum +=temp.top();
                temp.pop();
            }
            cout << sum << endl;
        }
        else if(command == "insert"){
            int num;
            cin >> num;
            if(pq.size() < k){
                pq.push(num);
            } else if(pq.top() < num){
                pq.pop();
                pq.push(num);
            }
        }
    }

    return 0;
}