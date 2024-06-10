#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int visited[10001];
int A,B;

void bfs(){
    queue<pair<int, string>> q;
    q.push({A,""});
    visited[A] = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int num = cur.first;
        string s = cur.second;
        if (num == B) {
            cout << s << "\n";
            return;
        }
        int D, S, L, R;
        // D 연산
        D = (num * 2) % 10000;
        if (!visited[D]) {
            visited[D] = 1;
            q.push(make_pair(D, s + 'D'));
        }
        // S 연산
        S = num - 1;
        if (S == -1) S = 9999;
        if (!visited[S]) {
            visited[S] = 1;
            q.push(make_pair(S, s + 'S'));
        }
        // L 연산
        L = (num * 10) % 10000 + num / 1000;
        if (!visited[L]) {
            visited[L] = 1;
            q.push(make_pair(L, s + 'L'));
        }
        // R 연산
        R = num / 10 + (num % 10) * 1000;
        if (!visited[R]) {
            visited[R] = 1;
            q.push(make_pair(R, s + 'R'));
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> A >> B;
        bfs();
        memset(visited, 0, sizeof(visited)); //초기화 안시켜주면 안됨
    }
}
