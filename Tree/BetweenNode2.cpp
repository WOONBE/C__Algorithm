//
// Created by 김헌우 on 2023/07/26.
//bfs로 풀이한거 가져옴

#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

vector<pair<int,int>> adj[1003];
int dist[1003] = { 0, };

int bfs(int start, int end) {
    int sum = 0;
    fill(dist, dist + 1003, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur]) {
            if (dist[nxt.first] != -1) continue;
            dist[nxt.first] = dist[cur] + nxt.second;
            q.push(nxt.first);
        }
    }

    return dist[end];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N-1; i++) {
        int from, to,dist;
        cin >> from >> to >> dist;
        adj[from].push_back({ to,dist });
        adj[to].push_back({ from,dist });
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) << "\n";
    }

}