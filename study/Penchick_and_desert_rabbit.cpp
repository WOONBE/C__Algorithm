#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int minVal;
    int maxVal;
    int length;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Interval> stk;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            Interval cur = { x, x, 1 };

            while (!stk.empty() && stk.back().maxVal > cur.minVal) {
                Interval top = stk.back(); stk.pop_back();
                cur.minVal = min(cur.minVal, top.minVal);
                cur.maxVal = max(cur.maxVal, top.maxVal);
                cur.length += top.length;
            }

            stk.push_back(cur);
        }

        for (const auto& interval : stk) {
            for (int i = 0; i < interval.length; i++) {
                cout << interval.maxVal << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
