//
// Created by 김헌우 on 2024/09/01.
//
#include <iostream>

using namespace std;

int a,b,c,d,e,f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d >> e >> f;
    for(long long x =-999; x<=999; x++){
        for(long long y = -999; y<=999; y++){
            if(a * x + b * y == c){
                if(d * x + e * y == f){
                    cout << x << ' ' << y <<"\n";
                }
            }
        }
    }










}
