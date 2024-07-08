#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string n;
vector<int> v;
bool found = false;

void DFS(vector<int>& curr, vector<bool>& used, int depth, int originalNum) {
    if (depth == n.size()) {
        int num = 0;
        for (int i = 0; i < curr.size(); ++i) {
            num = num * 10 + curr[i];
        }
        if (num > originalNum) {
            cout << num << endl;
            found = true;
        }
        return;
    }

    for (int i = 0; i < n.size(); ++i) {
        if (!used[i] && !found) {
            used[i] = true;
            curr.push_back(v[i]);
            DFS(curr, used, depth + 1, originalNum);
            curr.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int originalNum = stoi(n);

    for (int i = 0; i < n.size(); ++i) {
        v.push_back(n[i] - '0');
    }

    sort(v.begin(), v.end());

    vector<int> curr;
    vector<bool> used(n.size(), false);

    DFS(curr, used, 0, originalNum);

    return 0;
}
