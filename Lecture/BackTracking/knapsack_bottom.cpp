#include <vector>
#include <iostream>

using namespace std;
int d[100001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int w, value;
        cin >> w >> value;
        for (int j = k; j >= w; j--) {
            d[j] = max(d[j], d[j - w] + value);
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++)ans = max(ans, d[i]);
    cout << ans;
}