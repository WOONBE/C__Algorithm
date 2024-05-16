#include <iostream>
using namespace std;

int gcd(long long a, long long b) {
    long long  c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

//int lcm(int a, int b) {
//    return (a * b) / gcd(a, b);
//}

int main() {
    long long n1, n2;
    cin >> n1 >> n2;
    cout << gcd(n1, n2) << "\n";

}

