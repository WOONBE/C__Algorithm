#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll D, P, Q;
    cin >> D >> P >> Q;

    // 항상 P >= Q가 되도록 정렬
    if (P < Q) swap(P, Q);

    ll answer = D + (P - D % P) % P; // P로만 지불했을 때 초과 금액
    ll limit = min(D / P, Q); // P*i 반복의 상한선을 Q로 제한

    for (ll i = 0; i <= limit; i++) {
        ll cur = P * i;
        ll remain = D - cur;

        if (remain <= 0) {
            answer = min(answer, cur); // 이미 초과면 그대로 저장
        } else {
            // 부족한 금액만큼 Q로 채워야 함
            ll extra = (Q - (remain % Q)) % Q;
            answer = min(answer, cur + remain + extra);
        }
    }

    cout << answer << "\n";
    return 0;
}
