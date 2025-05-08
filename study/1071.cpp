#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N;
vector<int> v;

int main() {
    First;
    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N - 1; i++) {
        if (v[i] + 1 == v[i + 1]) {
            int end = i + 2;
            while (end < N && v[end] == v[i + 1]) {
                end++;
            }

            if (end == N) {
                // 뒤쪽 그룹이 끝까지 같음
                int start = i - 1;
                while (start >= 0 && v[start] == v[i]) {
                    start--;
                }

                if (start + 1 >= 0 && i + 1 < N) {
                    v[start + 1]++;
                    v[i + 1]--;
                }
            } else {
                // 뒤쪽 그룹과 swap
                swap(v[i + 1], v[end]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
