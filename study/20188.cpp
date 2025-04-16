#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
int N,a,b;
vector<int> v[300001];
ll ans,d[300001];
ll totalDepth = 0;


ll ret(ll n) {
    return n * (n - 1) / 2;
}

ll dfs(int cur) {
    d[cur] = 1;
    for (auto i : v[cur]) {
        if (!d[i]) {
            d[cur] += dfs(i);
        }
    }
    ans += ret(N) - ret(N - d[cur]);
    return d[cur];
}
int main(){
    First

    cin >> N;

    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    cout << ans - ret(N) << '\n';

}