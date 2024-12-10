#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    unordered_map<int, int> bag; // 키: 정수, 값: 해당 정수의 개수
    int unique_count = 0;        // 서로 다른 정수의 개수

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            if (bag[x] == 0) {
                unique_count++;
            }
            bag[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            bag[x]--;
            if (bag[x] == 0) {
                unique_count--;
            }
        } else if (type == 3) {
            cout << unique_count << endl;
        }
    }

    return 0;
}
