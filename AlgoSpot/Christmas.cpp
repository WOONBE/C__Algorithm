
#include<iostream>
#include<vector>
using namespace std;
// 문제 조건에 맞는 출력을 위한 MOD
const int MOD = 20091101;
int n, k;
// 각 상자에 담긴 인형의 수
int box[100000];
// 상자에 담긴 인형 갯수의 부분합을 k로 나눈 나머지
int psum[100001];
// psum 미리 구하기
// 첫번째 상자부터 주문하는 경우를 고려하여 psum의 첫번째 원소 전에 0을 삽입
void precalc() {
    psum[0] = 0;
    for (int i = 1; i <= n; i++)
        psum[i] = (psum[i - 1] + box[i - 1]) % k;
}
// 한번 주문해서 구입할 수 있는 방법의 수
int waysToBuy() {
    int ret = 0;
    vector<long long>count(k, 0);
    // count[i] = psum[]이 i인 경우의 수
    for (int i = 0; i <= n; i++)
        count[psum[i]]++;
    // count[i]가 2이상이면 그 중 두개를 뽑는 조합을 더함
    for (int i = 0; i < k; i++)
        if (count[i] >= 2)
            ret = (ret + (count[i] * (count[i] - 1)) / 2) % MOD;
    return ret;
}
// 겹치지 않고 몇 번이나 살 수 있는지
int maxBuys() {
    vector<int> ret(n + 1, 0);
    // prev[i] = psum이 i였던 마지막 위치
    vector<int> prev(k, -1);
    for (int i = 0; i <= n; i++) {
        if (i == 0)
            ret[i] = 0;
        else
            // i번째 상자를 고려하지 않는 경우
            ret[i] = ret[i - 1];
        // psum[i]와 같은 값이 이전에 발견 되었으면,
        // 이전 발견 위치에서부터 지금 위치까지 주문한 경우 고려
        int loc = prev[psum[i]];
        if (loc != -1)
            ret[i] = max(ret[i], ret[loc] + 1);
        // prev에 현재 위치 기록
        prev[psum[i]] = i;
    }
    return ret.back();
}
int main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> box[i];
        precalc();
        cout << waysToBuy() << " " << maxBuys() << endl;
    }
}