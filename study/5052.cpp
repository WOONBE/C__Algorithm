#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int T;


void solve() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        vector<string> v(n);
        unordered_set<string > s;
        bool isIn = false;

        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }

        sort(v.begin(), v.end()); //정렬 필수

        for(int i=0; i<n; i++){
            string prestr = "";
            for(int j=0; j<v[i].length()-1; j++){
                prestr += v[i][j];
                if(s.find(prestr) != s.end()){
                    isIn = true;
                    break;
                }
            }
            if (isIn) {
                break;
            }
            s.insert(v[i]);

        }
        if (isIn) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}

int main() {
    First
    solve();
    return 0;
}
