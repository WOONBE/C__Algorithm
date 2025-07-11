#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
#define First ios::sync_with_stdio(false); cin.tie(0);

void solve() {
    ll N;
    int M;
    cin >> N >> M;

    ll odd_num = (N + 1) / 2;
    ll even_num = N / 2;
    ll team1 = odd_num * odd_num;
    ll team2 = even_num * (even_num + 1);
    ll ans = team1 - team2;

    //이적한 선수들의 현재 팀 정보 저장
    unordered_map<ll, int> mp;

    for (int i = 0; i < M; ++i) {
     
        cout << ans << " "; //일단 유리도 출력
        
        if (i == M - 1) break;

        ll num;
        cin >> num;

        //이적할 선수의 팀 파악
        int cur_team;
        if (mp.count(num)) {
            cur_team = mp[num];
        } else {
            cur_team = (num % 2 != 0) ? 1 : 2;
        }
        if (cur_team == 1) {
            ans -= 2 * num;
            mp[num] = 2;
        } else {
            ans += 2 * num;
            mp[num] = 1;
        }
    }
    cout << "\n";
    cout.flush();
}

int main() {
    First
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}