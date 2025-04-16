#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        // 역순으로 정렬
        sort(v.rbegin(), v.rend());
        int cnt = 0;
        for(auto i : v){
            if(cnt + i <=k){
                cnt += i;
            }else{
                break;
            }
        }

        cout << k - cnt << '\n';
    }
    return 0;
}
