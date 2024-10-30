#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0);cout.tie(0); cin.tie(0);

int N, ans;
vector<int> populations;
vector<vector<int>> adj;

//입력, 연결여부 확인, 백트래킹으로 경우 나누기, 계산,
void input(){
    cin >> N;
    populations.resize(N+1,0);
    adj.resize(N+1);

    for (int i = 1; i <= N; i++) {
        cin >> populations[i];
    }
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int neighbor;
            cin >> neighbor;
            adj[i].push_back(neighbor);
            adj[neighbor].push_back(i);
        }
    }
}
bool isConnected(vector<int>& group){
    if(group.size() == 0) return false;
    bool visited[11] = {0,};
    queue<int> q;
    q.push(group[0]);
    visited[group[0]] = true;
    int cnt = 1;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto i : adj[cur]){
            if(!visited[i] && find(group.begin(), group.end(), i) != group.end() ){
                visited[i] = true;
                q.push(i);
                cnt++;
            }
        }
    }
    return group.size() == cnt;
}

void solve() {
    ans = 987654321;
    int limit = (1 << N);
    for (int bit = 1; bit < limit; bit++) {
        vector<int> groupA, groupB;
        int popA = 0, popB = 0;

        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                groupA.push_back(i + 1);
                popA += populations[i + 1];
            } else {
                groupB.push_back(i + 1);
                popB += populations[i + 1];
            }
        }

        if (isConnected(groupA) && isConnected(groupB)) {
            int diff = abs(popA - popB);
            ans = min(ans, diff);
        }
    }
    if (ans == 987654321) cout << -1;
    else cout << ans;
}


int main(){
    First
    input();
    solve();
    return 0;
}
