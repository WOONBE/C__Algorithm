#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
ll T,N,ans;

int main(){
    First

    cin >> T;

    while(T--){

        cin >> N;
        vector<ll> v(N+1,0);

        for(int i=0; i<N; i++){
            cin >> v[i];
        }
        ans = 1987654321;
        for(int i=0; i<N; i++){

            ll val = i;
            for(int j=i+1; j<N; j++){

                if(v[i] < v[j]){
                    val++;
                }
            }
            ans = min(ans,val);
        }
        cout << ans << "\n";
    }
}