#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, M;  // N은 세로 크기, M은 가로 크기
int height[1001][1001];  // 각 영토의 높이
ll tax[1001][1001];  // 각 영토의 세금
ll result[1001][1001];  // 각 영토의 계산된 세금 결과

map<int, vector<pii>> heightMap;  // 높이에 따라 영토들의 좌표를 저장
pii parent[1001][1001];  // 유니온 파인드를 위한 부모 배열
int groupHeight[1001][1001];  // 각 영토의 그룹 높이
int dx[4] = {1, 0, -1, 0};  // 상하좌우 방향
int dy[4] = {0, 1, 0, -1};  // 상하좌우 방향

// 유니온 파인드에서 부모를 찾는 함수
pii Find(int x, int y) {
    if (parent[x][y] == pii{-1, -1}) {
        return {x, y};
    }
    return parent[x][y] = Find(parent[x][y].first, parent[x][y].second);  // 경로 압축
}

// 두 집합을 병합하는 함수
void Union(pii p1, pii p2) {
    p1 = Find(p1.first, p1.second);
    p2 = Find(p2.first, p2.second);

    // 이미 같은 집합에 속하면 병합하지 않음
    if (p1 == p2) return;

    // 높이가 작은 집합을 큰 집합에 병합
    if (groupHeight[p1.first][p1.second] < groupHeight[p2.first][p2.second]) {
        swap(p1, p2);
    }
    parent[p2.first][p2.second] = p1;

    // 높이가 같으면 부모의 높이를 증가시킴
    if (groupHeight[p1.first][p1.second] == groupHeight[p2.first][p2.second]) {
        groupHeight[p1.first][p1.second]++;
    }

    // 세금을 병합
    tax[p1.first][p1.second] += tax[p2.first][p2.second];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // N, M 입력
    cin >> N >> M;

    // 높이와 세금 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> height[i][j];
            heightMap[height[i][j]].push_back({i, j});
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> tax[i][j];
        }
    }

    // 부모 배열 초기화
    fill(&parent[0][0], &parent[1000][1001], pii{-1, -1});

    // 높이가 낮은 순으로 처리
    for (auto &entry : heightMap) {
        int H = entry.first;  // 현재 처리할 높이
        vector<pii> &coords = entry.second;  // 현재 높이에 해당하는 좌표들

        for (auto &coord : coords) {
            int x = coord.first, y = coord.second;
            // 인접한 방향으로 Union 찾기
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                    if (height[nx][ny] <= height[x][y]) {
                        Union({x, y}, {nx, ny});  // 병합
                    }
                }
            }
        }

        // 병합 후 각 영토의 세금을 계산하여 결과에 반영
        for (auto &coord : coords) {
            int x = coord.first, y = coord.second;
            pii root = Find(x, y);  // 부모 찾기
            result[x][y] = tax[root.first][root.second];  // 부모 영토의 세금을 가져옴
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
