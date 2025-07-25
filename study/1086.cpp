#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
int N,K,cnt;
ll full;
vector<string> v;
vector<int> remain_val; //각 숫자열 k로 나눈 나머지
vector<int> pow_remain_val; //10의 제곱 k로 나눈 나머지
vector<int > str_len; //문자열 길이 저장
string num;
ll dp[1<<15][100]; //dp[state][remain] state까지 봤을때 K로 나눈 나머지가 remain이 되는 경우의 수

int find_remain(string& s){
    int cur=0;
    for(char c : s){
        cur = (cur * 10 + (c-'0')) % K;
    }
    return cur;
}

ll factorial(int n){
    ll result = 1;
    for(int i=2; i<=n; i++){
        result *= i;
    }
    return result;
}

ll gcd(ll a, ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}


int main(){
    First

    cin >> N;
    full = (1<<N)-1;
    v.resize(N);
    str_len.assign(N,0);
    remain_val.assign(N,0);
    pow_remain_val.assign(51,0);

    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    cin >> K;

    for(int i=0; i<N; i++){
        str_len[i] = v[i].length();
        remain_val[i] = find_remain(v[i]);
    }

    pow_remain_val[0] = 1;
    for(int i=1; i<=50; i++){
        pow_remain_val[i] = (pow_remain_val[i-1] * 10) % K;
    }

    dp[0][0] = 1;

    for(int state = 0; state < (1<<N); state++){
        for(int remain = 0; remain < K; remain++){
            if(dp[state][remain] == 0){ //경우가 없으면 점프
                continue;
            }

            for(int i=0; i<N; i++){
                if((state & (1<<i))) continue;
                int nxt_state = state | (1<<i);
                int nxt_remain = (remain * pow_remain_val[str_len[i]] + remain_val[i]) % K;
                dp[nxt_state][nxt_remain] += dp[state][remain];
            }
        }
    }

    ll p = dp[full][0];
    ll q = factorial(N);

    if(p == 0){
        cout<< "0/1" << "\n";
    }else{
        ll divisor = gcd(p,q);
        cout << p/divisor << "/" <<q/divisor <<"\n";
    }
}