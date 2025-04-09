#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N, K;
long long A0, B0, C0, D0;
vector<priority_queue<int>> cardQueues(4); // A, B, C, D용 우선순위 큐
long long x[4]; // 현재 A, B, C, D 값 저장

int main() {
    FastIO;
    cin >> N >> K;
    cin >> A0 >> B0 >> C0 >> D0;
    x[0] = A0; x[1] = B0; x[2] = C0; x[3] = D0;

    for (int i = 0; i < N; i++) {
        char type;
        int value;
        cin >> type >> value;
        int idx = type - 'A'; // 'A' ~ 'D' -> 0 ~ 3
        cardQueues[idx].push(value);
    }

    for (int i = 0; i < K; i++) {
        int selectedIdx = -1;
        double bestRatio = -1;

        for (int j = 0; j < 4; j++) {
            if (!cardQueues[j].empty()) {
                double ratio = (double)cardQueues[j].top() / x[j];
                if (ratio > bestRatio) {
                    bestRatio = ratio;
                    selectedIdx = j;
                }
            }
        }

        // 선택된 카드 사용
        int useValue = cardQueues[selectedIdx].top();
        cardQueues[selectedIdx].pop();
        x[selectedIdx] += useValue;
        cout << (char)('A' + selectedIdx) << ' ' << useValue << '\n';
    }

    return 0;
}
