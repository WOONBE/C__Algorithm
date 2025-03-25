#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>

using namespace std;
using ll = long long;

// 프로세스를 저장할 구조체
struct Process {
    ll priority, id, time_left;

    // 우선순위 큐에서 사용할 비교 연산자 (우선순위 내림차순, ID 오름차순)
    bool operator<(const Process &other) const {
        if (priority == other.priority) return id > other.id; // ID 오름차순
        return priority < other.priority; // 우선순위 내림차순
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll Q, n;
    cin >> Q >> n;

    priority_queue<Process> pq;
    vector<ll> queries(Q);
    map<ll, ll> results; // 특정 초의 실행 프로세스를 저장
    ll total_time = 0;

    for (int i = 0; i < n; i++) {
        ll Ai, Bi, Ci;
        cin >> Ai >> Bi >> Ci;
        pq.push({Ci, Ai, Bi});
        total_time += Bi;
    }

    for (int i = 0; i < Q; i++) {
        cin >> queries[i];
    }

    ll current_time = 1;
    ll prev_process_id = -1;

    while (!pq.empty()) {
        Process top = pq.top();
        pq.pop();

        // 현재 실행할 프로세스의 실행 종료 시간 계산
        ll next_time = current_time + top.time_left - 1;

        // 해당 구간 동안 실행된 프로세스 ID 저장
        if (results.find(current_time) == results.end()) {
            results[current_time] = top.id;
        }

        // 다음 실행 시점까지 한 번에 건너뛴다.
        prev_process_id = top.id;
        current_time = next_time + 1;

        // 다른 프로세스들의 우선순위 증가
        vector<Process> temp;
        while (!pq.empty()) {
            Process p = pq.top();
            pq.pop();
            temp.push_back({p.priority + top.time_left, p.id, p.time_left});
        }

        for (auto &p : temp) {
            pq.push(p);
        }
    }

    // 결과 처리
    for (ll Tc : queries) {
        auto it = results.upper_bound(Tc);
        if (it == results.begin()) {
            cout << prev_process_id << "\n";
        } else {
            --it;
            cout << it->second << "\n";
        }
    }

    return 0;
}
