#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N;
vector<vector<int>> v(4, vector<int>(4000));

int main() {
    First

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> v[0][i] >> v[1][i] >> v[2][i] >> v[3][i];
    }

    vector<int> v1, v2;

    // v1: A + B의 합 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v1.push_back(v[0][i] + v[1][j]);
        }
    }

    // v2: C + D의 합 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v2.push_back(v[2][i] + v[3][j]);
        }
    }

    // v1 오름차순 정렬, v2 내림차순 정렬
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());

    int srt = 0, ed = 0;  // 투 포인터 초기화
    long long cnt = 0;

    // 투 포인터를 이용해 합이 0인 경우 계산
    while (srt < v1.size() && ed < v2.size()) {
        int sum = v1[srt] + v2[ed];

        if (sum == 0) {
            // v1[srt]와 v2[ed]에 동일한 값이 몇 개 있는지 계산
            long long count1 = 1, count2 = 1;

            while (srt + 1 < v1.size() && v1[srt] == v1[srt + 1]) {
                count1++;
                srt++;
            }
            while (ed + 1 < v2.size() && v2[ed] == v2[ed + 1]) {
                count2++;
                ed++;
            }

            cnt += count1 * count2;
            srt++;
            ed++;
        } else if (sum < 0) {
            srt++;
        } else {
            ed++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
