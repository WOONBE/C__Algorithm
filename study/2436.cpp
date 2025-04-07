#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
ll Gcd, Lcm, a, b;

int main() {
    First

    cin >> Gcd >> Lcm;

    ll val = 1LL * Lcm / Gcd; // 두 수의 곱에서 Gcd를 나눈 값 = a * b
    ll min_val = 9987654321;

    for (ll i = 1; i <= sqrt(val); i++) {
        if (val % i == 0) {
            ll A_ = i;
            ll B_ = val / i;

            if (gcd(A_, B_) == 1) {
                ll A = A_ * Gcd;
                ll B = B_ * Gcd;

                if ((B - A) < min_val) {
                    a = A;
                    b = B;
                    min_val = B - A;
                }
            }
        }
    }

    cout << a << ' ' << b << "\n";
}
