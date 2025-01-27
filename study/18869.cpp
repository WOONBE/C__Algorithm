#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Universe {
    int id;              // 우주 ID
    vector<int> ranks;   // 각 우주의 순위 배열
};

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

vector<int> rankify(const vector<int>& planets) {
    int n = planets.size();
    vector<pair<int, int>> temp; // {행성 크기, 인덱스}
    vector<int> ranks(n);

    for (int i = 0; i < n; i++) {
        temp.push_back({planets[i], i});
    }

    // 행성 크기에 따라 정렬
    sort(temp.begin(), temp.end(), cmp);

    int rank = 1, temp_rank = 1;
    ranks[temp[0].second] = rank;

    for (int i = 1; i < n; i++) {
        if (temp[i].first != temp[i - 1].first) {
            rank += temp_rank;
            temp_rank = 1;
        } else {
            temp_rank++;
        }
        ranks[temp[i].second] = rank;
    }

    return ranks;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    vector<Universe> universes;

    // 각 우주의 데이터를 읽어 순위 배열로 변환
    for (int i = 0; i < M; i++) {
        vector<int> planets(N);
        for (int j = 0; j < N; j++) {
            cin >> planets[j];
        }

        vector<int> ranks = rankify(planets);
        universes.push_back({i, ranks});
    }

    // 균등한 우주의 쌍 계산
    int result = 0;

    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            if (universes[i].ranks == universes[j].ranks) {
                result++;
            }
        }
    }

    cout << result << '\n';
    return 0;
}
