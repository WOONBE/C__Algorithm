#include <bits/stdc++.h>
using namespace std;

long long N;
char answer;
long long total_len = 3;
#define First ios::sync_with_stdio(0); cin.tie(0);

void solve(long long N, int k, long long len) {
    long long prev_len = (len - (k + 3)) / 2;

    if (N <= prev_len) {
        solve(N, k - 1, prev_len);
    }
    else if (N <= prev_len + k + 3) {
        // 중간 부분의 시작점이면 'm', 아니면 'o'
        if (N == prev_len + 1) answer = 'm';
        else answer = 'o';
    }
    else {
        solve(N - (prev_len + k + 3), k - 1, prev_len);
    }
}

int main() {
    First
    cin >> N;

    int k = 0;

    while (total_len < N) {
        k++;
        total_len = total_len * 2 + (k + 3);
    }
    solve(N, k, total_len);
    cout << answer << "\n";
    return 0;
}