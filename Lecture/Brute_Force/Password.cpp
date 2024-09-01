#include <iostream>

//long long으로 타입 지정 안하면 터짐
using namespace std;
int T;
long long num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> num;
        bool isValid = true;

        for (int j = 2; j <= 1000000; j++) {
            if (num % j == 0) {
                cout << "NO" << "\n";
                isValid = false;
                break;
            }
        }

        if (isValid) {
            cout << "YES" << "\n";
        }
    }

    return 0;
}
