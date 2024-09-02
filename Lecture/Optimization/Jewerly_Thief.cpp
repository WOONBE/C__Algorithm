#include <iostream>
#include <set>
#include <cmath>
using namespace std;
//답은 잘나오는데 계속 출력초과 떠서 나중에 해결
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    First
    long long num;
    cin >> num;

    set<long long> s;

    // 루트 num까지의 약수를 찾아서 set에 추가
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            s.insert(i);
            if (i != num / i) {
                s.insert(num / i);
            }
        }
    }

    cout << s.size() << "\n";
    for (auto i : s) {
        cout << i << ' ';
    }
}
