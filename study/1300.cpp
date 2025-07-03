#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
ll N,K,num;
vector<ll> v;
int main(){
    cin >> N;
    cin >> K;
    ll left = 1;
    ll right = N*N;
    ll ans = 0;
    while(left<=right){
        ll mid = (left+right)/2;
        ll cnt = 0;
        for(int i=1; i<=N; i++){
            cnt += min(N,mid/i); //i * j <= mid이기에
        }
        if(cnt >= K){
            ans = mid;
            right = mid -1;
        }else{
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;

}