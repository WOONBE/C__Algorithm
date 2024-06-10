#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, F;
    cin >> N >> F;

    N /= 100;
    N *= 100;

    while (N % F != 0) N++;
    N %= 100;
    if (N < 10) cout << "0" << N << endl;
    else cout << N << endl;
    return 0;

}
