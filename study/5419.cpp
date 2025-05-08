#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

ll T, n;
vector<pair<ll, ll>> v;
vector<ll> tree;
vector<ll> y_list;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void update(ll node, ll start, ll end, ll idx) {
    if (idx < start || idx > end) return;
    if (start == end) {
        tree[node]++;
        return;
    }
    ll mid = (start + end) / 2;
    update(node * 2, start, mid, idx);
    update(node * 2 + 1, mid + 1, end, idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll start, ll end, ll l, ll r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    ll mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
    First;
    cin >> T;
    while (T--) {
        cin >> n;
        v.assign(n, {0, 0});
        y_list.clear();

        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
            y_list.push_back(v[i].second);
        }

        // 좌표 압축
        sort(y_list.begin(), y_list.end());
//        y_list.erase(unique(y_list.begin(), y_list.end()), y_list.end());
        map<ll, ll> y_compress;
        for (int i = 0; i < y_list.size(); i++) {
            y_compress[y_list[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            v[i].second = y_compress[v[i].second];
        }

        sort(v.begin(), v.end(), cmp);  // x 내림차순, y 오름차순

        ll size = y_list.size();
        tree.assign(4 * size, 0);

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll y_idx = v[i].second;
            ans += query(1, 0, size - 1, 0, y_idx);
            update(1, 0, size - 1, y_idx);
        }

        cout << ans << '\n';
    }
}
