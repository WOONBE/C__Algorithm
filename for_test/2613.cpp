#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int N,M;
int l = 0;
int r = 0;
int ans = 0;
vector<int> v;
//mid값을 넣었을때 몇개의 그룹 형성 가능한가 여부 확인
bool check(int num){
    int group_num = 1;
    int cur_val = 0;

    for(int i=0; i<v.size(); i++){
        if(cur_val + v[i] > num){
            cur_val = v[i];
            group_num++;
        }else {
            cur_val += v[i];
        }
    }
    return group_num <= M;
}


int main(){
    First

    cin >> N >> M;
    v.assign(N,0);

    for(int i=0; i<N; i++){
        cin >> v[i];
        l = max(l,v[i]);
        r += v[i];
    }

    while(l<=r){
        int mid = (l+r)/2;
        //m개 그룹 가능하면
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";

    int cur_cnt = 0;
    int cur_sum = 0;
    int group_made = 0;

    for (int i = 0; i < N; i++) {
        cur_sum += v[i];
        cur_cnt++;

        // 마지막 원소라면 무조건 출력하고 종료
        if (i == N - 1) {
            cout << cur_cnt << "\n";
            break;
        }
        // 그룹을 나누어야 하는 조건:
        // 1. 다음 구슬(v[i+1])을 더하면 최대 합(ans)을 초과하는 경우
        // 2. OR 남은 구슬 개수와 남은 만들어야 할 그룹 개수가 같아져서, 지금 안 자르면 나중에 구슬이 모자란 경우
        //    (남은 구슬: N - 1 - i, 남은 그룹: M - 1 - group_made)
        if (cur_sum + v[i + 1] > ans || (N - 1 - i) == (M - 1 - group_made)) {
            cout << cur_cnt << " ";
            cur_sum = 0;
            cur_cnt = 0;
            group_made++;
        }
    }

    return 0;
}