#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, T;
int srt, ed, select_num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> T;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int t = 0; t < T; t++) {
        cin >> srt >> ed >> select_num;


        vector<int> sub_v(v.begin() + (srt - 1), v.begin() + ed);
        sort(sub_v.begin(), sub_v.end());

        cout << sub_v[select_num - 1] << "\n";
    }

    return 0;
}
