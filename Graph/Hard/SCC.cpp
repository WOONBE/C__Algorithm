//
// Created by 김헌우 on 2023/07/31.
//코사라주 알고리즘, 더 좋은 코드 가져옴

#include "bits/stdc++.h"
using namespace std;

int V, E;
int A, B;

vector<int> graph[10001];
vector<int> inv_graph[10001]; //역으로 가는 부분 필요

bool visited[10001]; // SCC 돌면서 노드 체크
stack<int> stk;
vector<vector<int>> result;

void init()
{
    cin >> V >> E;

    while (E--) {
        cin >> A >> B;
        graph[A].push_back(B);
        inv_graph[B].push_back(A);
    }

    memset(visited, false, sizeof(visited));

    // 연결 요소 오름차순 정렬
    for (int i = 1; i <= V; i++) {
        sort(graph[i].begin(), graph[i].end());
        sort(inv_graph[i].begin(), inv_graph[i].end());
    }
}

void dfs(int node)
{
    visited[node] = true;

    for (auto num : graph[node]) {
        if (visited[num])
            continue;

        dfs(num);
    }

    stk.push(node);
}

void dfs_scc(int node, vector<int>& vec)
{
    visited[node] = true;
    vec.push_back(node);

    for (auto num : inv_graph[node]) {
        if (visited[num])
            continue;

        dfs_scc(num, vec);
    }
}

void SCC()
{
    memset(visited, false, sizeof(visited));

    vector<int> vec;

    while (!stk.empty()) {
        int start = stk.top();
        stk.pop();

        if (visited[start])
            continue;

        dfs_scc(start, vec);
        sort(vec.begin(), vec.end());
        result.push_back(vec);
        vec.clear();
    }
}

bool compare_vec(const vector<int>& v1, const vector<int>& v2)
{
    if (v1[0] < v2[0])
        return true;
    else
        return false;
}

void get_result()
{
    cout << result.size() << '\n';
    sort(result.begin(), result.end(), compare_vec);

    for (int i = 0; i < result.size(); i++) {
        for (auto num : result[i]) {
            cout << num << ' ';
        }
        cout << -1;
        if (i != result.size() - 1)
            cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    for (int node = 1; node <= V; node++) {
        if (visited[node])
            continue;

        dfs(node);
    }

    SCC();

    get_result();
}
