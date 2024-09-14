#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 모든 보석을 먹을 수 있는지 확인하는 함수
bool canCollectAllJewels(const vector<int>& arr, int start) {
    int n = arr.size();
    vector<int> jewels; // 보석의 위치 저장

    // 배열에서 보석의 위치를 저장
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            jewels.push_back(i);
        }
    }

    if (jewels.empty()) {
        return true; // 보석이 없다면 항상 수집 가능
    }

    int pos = start;
    while (!jewels.empty()) {
        int closestDist = n;  // 가장 가까운 거리 초기화
        int closestPos = -1;  // 가장 가까운 보석의 위치 초기화

        // 모든 보석들에 대해 가장 가까운 보석을 찾음
        for (int i = 0; i < jewels.size(); i++) {
            int dist = abs(pos - jewels[i]);  // 현재 위치에서 보석까지의 거리
            if (dist < closestDist) {
                closestDist = dist;
                closestPos = i;
            }
        }

        // 양쪽에 가장 가까운 보석이 있는지 확인
        int leftPos = -1, rightPos = -1;
        for (int i = 0; i < jewels.size(); i++) {
            if (jewels[i] < pos) {
                leftPos = jewels[i]; // 현재 위치의 왼쪽에 있는 보석
            } else if (jewels[i] > pos) {
                rightPos = jewels[i]; // 현재 위치의 오른쪽에 있는 보석
                break; // 오른쪽 보석을 찾으면 멈춤
            }
        }

        // 만약 양쪽에 보석이 존재하고, 그 거리가 같으면 욕심이 터짐
        if (leftPos != -1 && rightPos != -1) {
            int leftDist = abs(pos - leftPos);
            int rightDist = abs(pos - rightPos);
            if (leftDist == rightDist) {
                return false; // 욕심이 터짐
            }
        }

        // 가장 가까운 보석으로 이동
        pos = jewels[closestPos];
        jewels.erase(jewels.begin() + closestPos);  // 보석을 먹음
    }

    return true;
}

// 최소 이동거리를 찾는 함수
int findMinDistance(const vector<int>& arr, int m) {
    int n = arr.size();
    m -= 1; // 입력의 m은 1부터 시작하므로 0-index로 변환

    // 모든 가능한 시작 위치에 대해 보석을 수집할 수 있는지 확인
    vector<bool> canCollect(n, false);
    for (int i = 0; i < n; i++) {
        canCollect[i] = canCollectAllJewels(arr, i);
    }

    // 현재 위치에서 다 먹을 수 있으면 바로 리턴
    if (canCollect[m]) {
        return m;
    }

    // 양쪽으로 이동하면서 가장 가까운 지점을 찾기
    int minDistance = n;
    for (int i = 0; i < n; i++) {
        if (canCollect[i]) {
            int distance = abs(i - m);
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
    }

    return minDistance;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << findMinDistance(arr, M) << endl;
    return 0;
}
