#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
vector<ll> v;
int N;

int main(){
    First

    cin >> N;
    v.assign(N,0);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());

    int left = 0;
    int right = N-1;

    ll result = 2 * 1e10 + 7;
    ll left_result = 0;
    ll right_result = 0;
    while(left < right){
        ll cur_sum = v[left] + v[right];

        if(abs(cur_sum) <= result){
            left_result = v[left];
            right_result =  v[right];
            result = abs(cur_sum);
        }

        if(cur_sum < 0){//음수일때
            left++; //큰수로 당긴다
        }else if(cur_sum > 0){ //양수일때는 작은수로
            right--;
        }else{
            break; //0이면 break;
        }
    }
    cout << left_result << ' ' << right_result << "\n";
}