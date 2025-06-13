#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const ll Mx = 1e18;
int T,N;
ll ans;
vector<ll> arr;

bool check(vector<ll> & arr, ll k){
    int cnt = 0;
    for(int i=0; i<arr.size(); i++){
        if(i+1 == arr.size()){
            cnt++;
        }else{
            if(arr[i+1] - arr[i] <=k){
                i++;
            } else{
                cnt++;
            }
        }
    }
    return cnt<=1;
}


int main(){

    cin >> T;

    while(T--){
        cin >> N;
        arr.resize(N);

        for(int i=0; i<N; i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        ll left = 1;
        ll right = Mx;
        ans = Mx;
        while(left <= right){
            ll mid = (left + right)/2;
            if(check(arr,mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }

        }
        cout << ans << "\n";
    }



}