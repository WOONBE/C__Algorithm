//
// Created by 김헌우 on 2023/12/27.
//2063

#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int w[10000];
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> w[i];

    }
    sort(w, w+n);
    int t = n/2 +1;
    cout << w[t-1];
}
