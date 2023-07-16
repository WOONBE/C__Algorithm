//
// Created by 김헌우 on 2023/07/14.
//이건 밟을때의 case, 밟지 않을때의 case로 점화식 구성까지 했음
#include <bits/stdc++.h>
using namespace std;

int s[305];
int n;
int d[305][3]; //[k번째 계단을 밟을때][j = 1연속 or 2연속]

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
    if(n == 1){
        cout << s[1]; //1일때 접근에 소모 시간 줄임
        return 0;
    }
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = s[1]+s[2];
    for(int i = 3; i <= n; i++){
        d[i][1] = max(d[i-2][1],d[i-2][2])+s[i];
        d[i][2] = d[i-1][1]+s[i];
    }
    cout << max(d[n][1],d[n][2]);
}
