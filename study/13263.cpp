#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
ll n;
vector<ll> heights;
vector<ll> costs;

int main(){
    First
    cin >> n;
    heights.assign(n,0);
    costs.assign(n,0);

    for(int i=0; i<n; i++){
        cin >> heights[i];
    }
    for(int i=0; i<n; i++){
        cin >> costs[i];
    }
    ll result = 1e18;
    ll first_cost = costs[0];
    for(int i=1; i<n; i++){
        result = min(result, (first_cost * heights[i] + costs[i] * heights[n-1]));
    }

    cout << result << "\n";

}