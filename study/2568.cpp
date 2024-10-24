#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

ll N;
vector<pair<ll, ll>> jun;

int main() {
    First;
    cin >> N;
    ll num, jun_num;

    for (int i = 0; i < N; i++) {
        cin >> num >> jun_num;
        jun.push_back({num, jun_num});
    }

    // 전봇대 번호 기준으로 정렬
    sort(jun.begin(), jun.end());

    vector<ll> LIS;          // LIS의 값들
    vector<ll> idx(N, 0);   // 각 원소의 LIS 길이를 저장
    vector<ll> lis_idx;      // 각 LIS의 원래 인덱스를 저장

    // LIS 계산
    for (int i = 0; i < N; i++) {
        // 이진 탐색으로 현재 전봇대 값의 위치 찾기
        ll low = 0, high = LIS.size();

        while (low < high) {
            ll mid = low + (high - low) / 2;
            if (LIS[mid] < jun[i].second) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (low == LIS.size()) {
            // 새로운 LIS가 확장되는 경우
            LIS.push_back(jun[i].second);
            lis_idx.push_back(i); // 현재 인덱스 저장
            idx[i] = LIS.size();  // 현재 LIS 길이 저장
        } else {
            // 기존 LIS의 값을 대체하는 경우
            idx[i] = low + 1; // 현재 인덱스의 LIS 길이를 업데이트
            LIS[low] = jun[i].second; // LIS의 값을 업데이트
            lis_idx[low] = i; // 원래 인덱스를 업데이트
        }
    }

    // LIS의 길이
    int size = LIS.size();
    cout << N - size << '\n'; // 삭제할 전봇대의 개수 출력

    // 삭제할 전봇대 번호를 저장
    vector<ll> trash;
    for (int i = N - 1; i >= 0; i--) {
        if (idx[i] == size) {
            size--; // 현재 LIS의 길이 감소
        } else if (idx[i] > 0) {
            trash.push_back(jun[i].first); // 삭제할 전봇대 번호 저장
        }
    }

    // 삭제할 전봇대 번호를 오름차순으로 정렬 후 출력
    sort(trash.begin(), trash.end());
    for (auto i : trash) {
        cout << i << '\n';
    }

    return 0;
}
