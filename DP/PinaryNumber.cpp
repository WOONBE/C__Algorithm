#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll pi[100][2]; //n자리에 0,1이 오는지 판단

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    pi[1][1] = 1LL; //0부터 시작은 불가능
    for(int i = 2; i <= n; ++i){
        pi[i][0] = pi[i-1][0] + pi[i-1][1]; //0은 앞에 1,0 다 가능
        pi[i][1] = pi[i-1][0]; //11은 불가능
    }
    cout << pi[n][0] + pi[n][1];
}