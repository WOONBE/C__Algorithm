#include <bits/stdc++.h>
using namespace std;

int phone[10000], Y, M;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int n = 0; n < N; n++) cin >> phone[n];

    for(int n = 0; n < N; n++) Y += ((phone[n] / 30) + 1) * 10; //최소 1은 잡아야 하니까 +1

    for(int n = 0; n < N; n++) M += ((phone[n] / 60) + 1) * 15;

    if(Y < M) cout << "Y " << Y;
    else if(Y > M) cout << "M " << M;
    else cout << "Y M " << Y;
}