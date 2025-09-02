#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int N, M, k;
int parent[10001];
int cost[10001];


int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b) {

        if (cost[a] < cost[b]) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }
}

int main() {
    First;

    cin >> N >> M >> k;


    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        cin >> cost[i];
    }


    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        Union(v, w);
    }


    ll total_cost = 0;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) {
            total_cost += cost[i];
        }
    }

    if (total_cost <= k) {
        cout << total_cost << "\n";
    } else {
        cout << "Oh no" << "\n";
    }
    return 0;
}