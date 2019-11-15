#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back()
#define ll long long
#define sz size()
#define all(x) x.begin(), x.end()
#define forn(x) for(ll i=1;i<=x;i++)
#define sforn(x, y) for(ll i=1;i<=x;i++)for(ll j=1;j<=y;j++)
#define pii pair<ll, ll>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

/*
    LOL KEK CHEBUREK

    PIHALITI

 */
ll arr[200100];
ll used[200100];
int main(){ speed;
    ll n, d;
    cin >> n >> d;
    for(ll i=1;i<=n;i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+n);
    reverse(arr+1, arr+1+n);
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        if(!used[i]){
            used[i] = 1;
            ++ans;
            for(ll j=i+1;j<=n;j++){
                if(!used[j] && arr[i] + arr[j] <= d){
                    used[j] = 1;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}