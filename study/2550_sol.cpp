#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


vector<int> switches; //i번 위치의 스위치 번호

vector<int> pos; //전구 번호의 위치 매핑

vector<int> light_pos; //i 위치 스위치 누르면 켜지는 전구의 위치
vector<int> dp; //길이를 저장할 배열
vector<int> pre; //이전에 방문한 위치 저장(역추적용)
vector<int> switch_num; //방문한 스위치 번호 저장
int max_len = 0; //리턴할 최대 길이
int last_idx = 0; //마지막으로 방문한 지점(여기서부터 역으로 추적)

int N;
int main(){

    First
    cin >> N;
    switches.resize(N+1);
    pos.resize(N+1);
    light_pos.resize(N+1);
    dp.resize(N+1);
    pre.resize(N+1);

    for(int i=1; i<=N; i++){
        cin >> switches[i]; //i 위치의 스위치 번호 매핑

    }
    for(int i=1; i<=N; i++){
        int light_num;
        cin >> light_num;
        pos[light_num] = i; //전구 번호가 어떤 위치에 있는지 매핑

    }
    for(int i=1; i<=N; i++){
        light_pos[i] = pos[switches[i]]; //i위치의 스위치 눌렀을때의 전구 위치를 매핑
    }
    fill(dp.begin(),dp.end(),1);


    for(int i=1; i<=N; i++){
        pre[i] = -1;
        for(int j=1; j<i; j++){
            if(light_pos[j] < light_pos[i] && dp[j] + 1 > dp[i]){
//                dp[i] = max(dp[i], dp[j] + 1);
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        if(dp[i] > max_len){
            max_len = dp[i];
            last_idx = i;
        }
    }

    cout << max_len << "\n";

    while(last_idx != -1){
        switch_num.push_back(switches[last_idx]);
        last_idx = pre[last_idx];
    }

    sort(switch_num.begin(),switch_num.end());

    for(auto i : switch_num){
        cout << i << ' ';
    }
    cout << "\n";
    return 0;

}
