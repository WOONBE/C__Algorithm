#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long N, X;
vector<long long> v;

int main() {
    First
    cin >> N >> X;

    v.resize(N, 0);

    for (long long i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    long long cnt = 0;
    long long l_idx = 0;
    long long r_idx = N - 1;
    long long remain = 0;

    //일단 꽉 차있는 애들 제거
    for(int i=0; i<N; i++){
        if(v[i] == X){
            r_idx--;
            cnt++;
        }
    }

    // 투 포인터 방식으로 합을 검사
    //교차될때의 값을 남은 값으로 추가해준(남은 값 3개 더하면 1병 되는거 알고 풀어야함)
    while (l_idx <= r_idx) {
        long long sum = v[l_idx] + v[r_idx];

        if(l_idx == r_idx){
            remain++;
            break;

        }

        // 두 값의 합이 X 이상인 경우
        if (sum >= (X+1)/2) {
            cnt++;
            r_idx--;  // 큰 값을 줄여서 다시 확인
            l_idx++; //쌍으로 빼줘야해서 l도 옮김
        } else {
            l_idx++;  //값이 더 작은 경우는 작은값만 올리면 된다
            remain++;
        }
    }
    //단순히 더하는게 아니라 가장 가깝게 더하는게 중요함
    //조건 통과해도 더 적합한 값이 될때까지 달림
    //안담긴 애들을 또 모아서 리턴하는 게  필요함

    long long ans = cnt + remain/3;

    cout << ans  << "\n";

    return 0;
}
