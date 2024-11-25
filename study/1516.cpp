#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> adj[501];
int tme[501];
int result[501];
int degree[501];

int N;
void input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> tme[i];
        while(true){
            int num;
            cin >> num;
            if(num == -1) break;
            adj[num].push_back(i);
            degree[i]++;
        }
    }
}
void solve(){
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(degree[i] == 0){
            q.push(i);
            result[i] = tme[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int nxt : adj[cur]) {

            result[nxt] = max(result[nxt], result[cur] + tme[nxt]);

            degree[nxt]--;

            if (degree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << '\n';
    }

}
int main(){
    First
    input();
    solve();

}