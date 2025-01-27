#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 6 != 2 && n % 6 != 3) {
        for (int i = 1; i <= n / 2; i++) {
            cout << 2 * i - 1 << "\n";
        }
        if (n % 2 == 1) {
            cout << n << "\n";
        }
        for (int i = 1; i <= n / 2; i++) {
            cout << 2 * i << "\n";
        }
    }
    else if (n % 6 == 2) {
        for (int i = 1; i <= n / 2; i++) {
            cout << 2 * i << "\n";
        }
        cout << 3 << "\n";
        cout << 1 << "\n";
        for (int i = n / 2 + 2; i < n - 1; i++) {
            cout << 2 * (i - n / 2 + 1) + 1 << "\n";
        }
        cout << 5 << "\n";
    }
    else if (n % 6 == 3) {
        for (int i = 2; i <= n / 2; i++) {
            cout << 2 * i << "\n";
        }
        cout << 2 << "\n";

        for (int i = n / 2; i < n - 2; i++) {
            cout << (i - n / 2 + 2) * 2 + 1 << "\n";
        }
        cout<< 1 << "\n";
        cout << 3 << "\n";
    }

    return 0;
}
