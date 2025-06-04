#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y, Z, P;
    cin >> X >> Y >> Z >> P;

    vector<int> A(X), B(Y), C(Z);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;
    for (int &x : C) cin >> x;

    // 미리 Cmin, Cmax 계산
    int Cmin = *min_element(C.begin(), C.end());
    int Cmax = *max_element(C.begin(), C.end());

    // B 정렬 (이진 탐색을 위해)
    sort(B.begin(), B.end());

    int answer = 0;

    for (int a : A) {
        // target은 Bob이 선택해야 할 이상적인 Cone의 기준점
        int target = P - a - (Cmin + Cmax) / 2;

        // 이진 탐색으로 target과 가장 가까운 b를 찾음
        auto it = lower_bound(B.begin(), B.end(), target);

        vector<int> candidates;
        if (it != B.end()) candidates.push_back(*it);
        if (it != B.begin()) candidates.push_back(*prev(it));

        int f = INT_MAX;
        for (int b : candidates) {
            int price1 = abs(a + b + Cmin - P);
            int price2 = abs(a + b + Cmax - P);
            int score = max(price1, price2); // Alice가 선택할 최악의 Topping

            f = min(f, score); // Bob이 선택할 최선의 Cone 결과
        }

        answer = max(answer, f); // Alice는 이 중 최대 점수를 선택
    }

    cout << answer << '\n';
    return 0;
}
