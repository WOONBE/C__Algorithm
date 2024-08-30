#include <iostream>
#include <vector>
using namespace std;

vector<int> removeBlocks(const vector<int>& v, int s, int e) {
    vector<int> result;
    for (int i = 0; i < v.size(); ++i) {
        if (i < s - 1 || i >= e) {
            result.push_back(v[i]);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> blocks(n);
    for (int i = 0; i < n; ++i) {
        cin >> blocks[i];
    }

    int s1, e1, s2, e2;
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    blocks = removeBlocks(blocks, s1, e1);


    blocks = removeBlocks(blocks, s2, e2);

    // 결과 출력
    cout << blocks.size() << endl;
    for (int block : blocks) {
        cout << block << endl;
    }

    return 0;
}
