#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX 201

using namespace std;

int A, B, C;
bool visited[MAX][MAX][MAX];
vector<int> V;

void Input() {
    cin >> A >> B >> C;
}

void Solution() {
    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(0, 0, C));

    while (!Q.empty()) {
        int a, b, c;
        tie(a, b, c) = Q.front();
        Q.pop();

        if (visited[a][b][c]) continue;
        visited[a][b][c] = true;

        if (a == 0) V.push_back(c);

        // A물통에서 B물통으로 줄 때
        if (a + b > B) Q.push(make_tuple(a + b - B, B, c));
        else Q.push(make_tuple(0, a + b, c));

        // A물통에서 C물통으로 줄 때
        if (a + c > C) Q.push(make_tuple(a + c - C, b, C));
        else Q.push(make_tuple(0, b, a + c));

        // B물통에서 A물통으로 줄 때
        if (b + a > A) Q.push(make_tuple(A, b + a - A, c));
        else Q.push(make_tuple(b + a, 0, c));

        // B물통에서 C물통으로 줄 때
        if (b + c > C) Q.push(make_tuple(a, b + c - C, C));
        else Q.push(make_tuple(a, 0, b + c));

        // C물통에서 A물통으로 줄 때
        if (c + a > A) Q.push(make_tuple(A, b, c + a - A));
        else Q.push(make_tuple(c + a, b, 0));

        // C물통에서 B물통으로 줄 때
        if (c + b > B) Q.push(make_tuple(a, B, c + b - B));
        else Q.push(make_tuple(a, b + c, 0));
    }

    sort(V.begin(), V.end());
    for (int i : V) {
        cout << i << " ";
    }
    cout << endl;
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
