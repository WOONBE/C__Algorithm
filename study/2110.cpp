#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
ll N,C;
vector<ll> v;
int main(){
    First

    cin >> N >> C;
    v.assign(N,0);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());

    ll left = 0;
    ll right = v[N-1] - v[0];

    ll ans = 1e10;
    while(left <= right){
        ll mid = (left+right)/2;
        int cnt = 1; //이거 1부터 시작해야함(일단 설치하고 갔다는게 전제)
        int idx = 0;
        for(int i=1; i<N; i++){
            if(v[i] - v[idx] >= mid){
                cnt++;
                idx = i;
            }
        }
        if(cnt >= C){ //C개 이상이면 거리 up
            ans = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout << ans << "\n";
}
//최솟값을 최대로