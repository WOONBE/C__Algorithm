#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

double X, Y, D, T, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> Y >> D >> T;

    double diag = sqrt(pow(X, 2) + pow(Y, 2));
    cout << fixed;
    cout.precision(9);

    if (D < T) // 점프하는것보다 걷는게 더 빠를 때
    {
        cout << diag << '\n';
    }
    else
    {
        ans = diag;

        int jump = diag / D; // 점프 횟수
        diag -= jump * D; // 남은 거리

        if (jump == 0) ans = min(ans, min(T + D - diag, 2.0 * T));
        else ans = min(ans, min(jump * T + diag, (jump + 1.0) * T));

        cout << ans << '\n';
    }


}
