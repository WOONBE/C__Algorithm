#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    First

    long long N;
    cin >> N;

    vector<long long> v(N);
    for (long long i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<long long> lis; // LIS의 각 원소를 저장할 배열

    for (long long i = 0; i < N; i++) {
        long long low = 0, high = lis.size(); // lis 벡터의 크기

        // 이분 탐색
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (lis[mid] < v[i]) {
                low = mid + 1; // v[i]가 lis[mid]보다 크면 오른쪽으로
            } else {
                high = mid; // v[i]가 lis[mid]보다 작거나 같으면 왼쪽으로
            }
        }

        // low는 현재 v[i]를 삽입할 위치
        if (low == lis.size()) {
            lis.push_back(v[i]); // 새로운 원소를 추가
        } else {
            lis[low] = v[i]; // 기존 원소를 교체
        }
    }

    // LIS의 길이는 lis의 크기
    cout << lis.size() << "\n";

    return 0;
}
