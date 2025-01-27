#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int T, k, num;
string s;

int main() {
    cin >> T;

    while (T--) {
        cin >> k;

        // 최대값을 위한 우선순위 큐 (내림차순)
        priority_queue<int> maxPQ;

        // 최소값을 위한 우선순위 큐 (오름차순)
        priority_queue<int, vector<int>, greater<>> minPQ;

        // 값의 존재 여부를 확인하기 위한 맵
        unordered_map<int, int> countMap;

        for (int i = 0; i < k; i++) {
            cin >> s >> num;

            if (s == "I") {
                maxPQ.push(num);
                minPQ.push(num);
                countMap[num]++;
            } else if (s == "D") {
                if (num == 1) {  // 최대값 제거
                    while (!maxPQ.empty() && countMap[maxPQ.top()] == 0) {
                        maxPQ.pop();
                    }
                    if (!maxPQ.empty()) {
                        int maxVal = maxPQ.top();
                        maxPQ.pop();
                        countMap[maxVal]--;
                    }
                } else if (num == -1) {  // 최솟값 제거
                    while (!minPQ.empty() && countMap[minPQ.top()] == 0) {
                        minPQ.pop();
                    }
                    if (!minPQ.empty()) {
                        int minVal = minPQ.top();
                        minPQ.pop();
                        countMap[minVal]--;
                    }
                }
            }
        }

        // 동기화: 유효하지 않은 값 제거
        while (!maxPQ.empty() && countMap[maxPQ.top()] == 0) {
            maxPQ.pop();
        }
        while (!minPQ.empty() && countMap[minPQ.top()] == 0) {
            minPQ.pop();
        }

        // 출력
        if (maxPQ.empty() || minPQ.empty()) {
            cout << "EMPTY" << "\n";
        } else {
            cout << maxPQ.top() << ' ' << minPQ.top() << "\n";
        }
    }

    return 0;
}
