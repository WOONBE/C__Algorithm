#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v; // 벡터를 동적으로 초기화

// 분할 정복 함수
long long solve(int st, int ed) {
    if (st == ed) {
        return (long long)v[st] * v[st];
    }

    int mid = (st + ed) / 2;

    // 왼쪽과 오른쪽 구간에서의 최대값
    long long left = solve(st, mid);
    long long right = solve(mid + 1, ed);

    // 병합 과정에서 중간(mid)을 포함하는 최대값 계산
    int l = mid;
    int r = mid;
    long long sum = v[mid];
    long long result = (long long)v[mid] * v[mid];
    int min_val = v[mid];

    // l과 r을 확장하며 최대값 갱신
    while (l > st || r < ed) {
        if (r < ed && (l == st || v[r + 1] >= v[l - 1])) {
            sum += v[++r];
            min_val = min(min_val, v[r]);
        } else {
            sum += v[--l];
            min_val = min(min_val, v[l]);
        }
        result = max(result, (long long)min_val * sum);
    }

    // 전체 구간에서의 최대값 반환
    return max({result, left, right});
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(nullptr); // 입출력 분리

    cin >> N;
    v.resize(N); // 벡터 크기 동적 설정

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cout << solve(0, N - 1) << "\n";
    return 0;
}
