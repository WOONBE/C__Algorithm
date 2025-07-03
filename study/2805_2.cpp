#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
ll N,M;
vector<ll> v;
int main(){
    First
    cin >> N >> M;
    v.assign(N,0);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    ll ans = 0;

    ll left = 1;
    ll right = v[N-1];

    while(left <= right){
        ll mid = (left+right) /2;
        ll len = 0;
        for(int i=0; i<N; i++){
            if(v[i] - mid > 0){
                len += v[i]-mid;
            }else continue;
        }
        if(len >= M){ //최대의 높이를 가지도록 절단기 높이 up
            if(mid > ans) ans = mid;
            left = mid+1;
        }else{//절단기 높이 줄임
            right = mid-1;
        }
    }
    cout << ans << "\n";
}