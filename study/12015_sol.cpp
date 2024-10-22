#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define First ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
#define INF 21111987654321;
int N;
ll dp[100001][5];
int dx[5] = {0,1,0,-1,0};
int dy[5] = {0,0,1,0,-1};
vector<pair<ll,ll>> v;

ll cal_dist(ll x, ll y,ll idx, ll dir) {
    if(idx == N) return 0;
    if(dp[idx][dir] != -1) {
        return dp[idx][dir];
    }

    dp[idx][dir] = INF;
    for(int i=0; i<5; i++) {
        ll nx = v[idx+1].first + dx[i];
        ll ny = v[idx+1].second + dy[i];
        if(nx <1 || ny < 1 || nx>100000 || ny>100000) continue;
        ll dist = abs(x - nx) + abs(y - ny);
        dp[idx][dir] = min(dp[idx][dir], dist + cal_dist(nx,ny,idx+1,i));
    }
    return  dp[idx][dir];
}


void input() {
    cin >> N;
    v.resize(N+1);
    cin >> v[0].first >> v[0].second;
    for(int i=1; i<=N; i++) {
        cin >> v[i].first >> v[i].second;
    }
}

int main() {
    First
    input();
    memset(dp,-1,sizeof(dp));
    cout << cal_dist(v[0].first,v[0].second,0,0) << "\n";

}