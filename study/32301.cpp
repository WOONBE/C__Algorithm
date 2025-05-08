#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m; n *= 3; m *= 3;
    if (n > m || m * 3 > n * 7.5) {
        cout << "NO\n";
        return 0;
    }
    if(n == 3 && m == 6) return !(cout << "NO");
    cout << "YES\n";
    for(int i = 1; i < n; i++) cout << i << ' ' << i+1 << '\n';
    cout << n << " 1\n";
    m -= n;
    for(int i = 1; i < n && m; i += 6){
        cout << i << ' ' << i+3 << '\n';
        cout << i+1 << ' ' << i+4 << '\n';
        cout << i+2 << ' ' << i+5 << '\n';
        m -= 3; if(!m) return 0;
        cout << i << ' ' << i+2 << '\n';
        cout << i+2 << ' ' << i+4 << '\n';
        cout << i+4 << ' ' << i << '\n';
        m -= 3; if(!m) return 0;
        cout << i+1 << ' ' << i+3 << '\n';
        cout << i+3 << ' ' << i+5 << '\n';
        cout << i+5 << ' ' << i+1 << '\n';
        m -= 3;
    }
}