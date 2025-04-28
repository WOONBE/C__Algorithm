#include <iostream>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
ll T,N;
int main(){
    First

    cin >> T;

    while(T--){
        cin >> N;
        ll num = 1;
        ll ans = 3 * (1<<(num-1)) -2;

        while(ans < N){
            num++;
            ans = 3 * (1<<(num-1)) -2;

        }
        cout << num << "\n";

    }

}