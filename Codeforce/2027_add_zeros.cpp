#include "bits/stdc++.h"

using namespace std;

long long a[300001];
map<long long, vector<long long>> mp;
map<long long, bool> check;

void dfs(long long x) {
    check[x] = true;
    for (auto it = mp[x].begin(); it != mp[x].end(); it++) {
        long long now = *it;
        if (check[now])continue;
        dfs(now);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        mp.clear();
        check.clear();
        long long n;
        cin >> n;
        for (long long i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (long long i = 2; i <= n; i++) {
            long long x = i + (a[i] - 1);
            long long y = (x - 1LL + (long long)i);
            mp[x].push_back(y);
        }

        for (auto it = mp[n].begin(); it != mp[n].end(); it++) {
            dfs(*it);
        }
        if (check.size()) {
            cout << (*check.rbegin()).first << '\n';
        }
        else {
            cout << n << '\n';
        }
    }
}