#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
vector<ll> v;
ll N,K;
int main(){
    First
    cin >> N >> K;
    v.assign(N,0);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    ll left = 1;
    ll right = v[N-1];
    ll ans = 0;
    while(left <= right){
        ll mid = (left+right)/2;
        ll cnt = 0;
        for(ll i=0; i<N; i++){
            cnt += (v[i] / mid);
        }
        if(cnt >=K){ //충분히 작을때
            left = mid+1;
            if(mid>ans) ans = mid;
        }else{
            right = mid-1;
        }
    }
    cout << ans << "\n";
}