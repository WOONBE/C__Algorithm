//
// Created by 김헌우 on 2023/06/27.
//
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll POW(ll a, ll b, ll m){
    if(b==1) return a % m;
    ll val = POW(a, b/2, m);
    val = val * val % m;  //타임 아웃 방지하려고 b/2 활용하여 풀이
    if(b%2 == 0) return val; //2로 나눠지면 그냥 리턴
    return val * a % m; //홀수면 한번더 곱해서 값 리턴
}

 int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;
    cin >> a >> b >> c;
    cout << POW(a,b,c);

}