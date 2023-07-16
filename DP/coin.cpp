//
// Created by 김헌우 on 2023/07/15.
//
#include "bits/stdc++.h"
using namespace std;

int pay[10005], price[10005];

int n,m; //n은 pay 종류, m은 가격
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        fill(price,price+10005,0); //price 안의 수를 0으로 초기화(이 부분 햇갈려서 오류)
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> pay[i];
        }
        cin >> m;
        price[0] = 1; //하나도 안쓰는 경우로 하나
        for(int i=0; i<n;i++)
            for(int j = pay[i]; j<=m; j++)
                price[j] += price[j-pay[i]]; //이걸 pay[j]로 하는 바람에 시간 오래걸림
        cout << price[m] << "\n"; //m말고 n으로 잘못 적어서 틀렸음
    }
}
