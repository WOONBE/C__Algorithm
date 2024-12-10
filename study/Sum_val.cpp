#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> L(N), R(N);
    long long sumL = 0, sumR = 0;
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        sumL += L[i];
        sumR += R[i];
    }


    if (sumL > 0 || sumR < 0) {
        cout << "No" << endl;
        return 0;
    }

    vector<long long> X = L;
    long long sumX = sumL;
    for (int i = 0; i < N; i++) {
        long long d = min(R[i] - L[i], -sumX);
        X[i] += d;
        sumX += d;
    }

    cout << "Yes" << endl;
    for (int i = 0; i < N; i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    return 0;
}