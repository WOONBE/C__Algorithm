//
// Created by 김헌우 on 2023/07/14.
//점화식 세우면 해결 fi[i][k]= i가 k 호출한 횟수

#include "bits/stdc++.h"
using namespace std;

int fi[42][2]; //2는 0아니면 1

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fi[0][0] = 1;
    fi[1][1] = 1;

    for(int i=2;i<=40;i++){
        fi[i][0] = fi[i - 1][0] + fi[i - 2][0];
        fi[i][1] = fi[i - 1][1] + fi[i - 2][1];
    }

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        cout << fi[n][0] << " " << fi[n][1] << endl;
    }

}

