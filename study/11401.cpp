#include <bits/stdc++.h>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

ll val = 1000000007;
int N,K;
vector<ll> factorial;

ll power(ll num, ll exp){
    ll ans = 1;
    num %= val;
    while(exp > 0){
        if(exp % 2){ //홀수면 한번 더 곱해서 양수로
            ans = (ans * num) % val;
        }
        num = num*num % val;
        exp /=2;
    }
    return ans;
}
int main(){
    First

    cin >> N >> K;
    factorial.assign(N+1,0);
    factorial[0] = 1;
    for(int i=1; i<=N; i++){
        factorial[i] = (factorial[i-1] * i) % val;
    }
    ll up = factorial[N];
    ll down = (factorial[K] * factorial[N-K]) % val;

    down = power(down,val-2);

    ll result = (up * down) % val;

    cout << result << "\n";
    return 0;
}