#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
ll N,B;
const int val = 1000;
vector<vector<ll>> v;

vector<vector<ll>> multiply(vector<vector<ll>> a, vector<vector<ll>> b){
    vector<vector<ll>> c(N, vector<ll>(N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                c[i][j] += (a[i][k] * b[k][j]);
            }
            c[i][j] %= 1000;
        }
    }
    return c;
}
vector<vector<ll>> power(vector<vector<ll>> a,ll exp){
    if(exp == 1){
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                a[i][j] %= 1000;
            }
        }
        return a;
    }
    vector<vector<ll>> half = power(a, exp / 2);;
    vector<vector<ll>> result = multiply(half,half);
    if(exp % 2 == 1){
        result = multiply(result,a);
    }
    return result;
}


int main(){
    First
    cin >> N >> B;
    v.assign(N,vector<ll>(N,0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> v[i][j];
        }
    }
    vector<vector<ll>> ans = power(v,B);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << ans[i][j] << ' ';
        }cout << "\n";
    }
    return 0 ;
}