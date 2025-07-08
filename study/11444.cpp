#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
#define MOD 1000000007
typedef long long ll;

ll n;
vector<vector<ll>> v = {{1,1},{1,0}};
vector<vector<ll>> multiply(vector<vector<ll>> a,vector<vector<ll>> b){
    vector<vector<ll>> c(2,vector<ll>(2,0)); //배열 할당필요
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++) {
            for(int k=0; k <2; k++){
                c[i][j] += (a[i][k] * b[k][j]);
            }
            c[i][j]%= MOD;//수정
        };
    }
    return c;
}

vector<vector<ll>> power(vector<vector<ll>> a, ll exp){
    if(exp == 1){
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a.size(); j++){
                a[i][j] % MOD;
            }
        }
        return a;
    }
    vector<vector<ll>> half = power(a,exp/2);
    vector<vector<ll>> ans = multiply(half,half);
    if(exp % 2){
        ans = multiply(ans,a);
    }
    return ans;
}

int main(){
    First
    cin >> n;

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    vector<vector<ll>> result = power(v,n-1);

    cout << result[0][0] << "\n";

}