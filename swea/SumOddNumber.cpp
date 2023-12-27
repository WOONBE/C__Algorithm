//
// Created by 김헌우 on 2023/12/27.
//2072

#include <algorithm>
#include <iostream>

using namespace std;

int main(){

    int n,N;
    cin >> N;
    for(int tc=0; tc<N; tc++){
        int sum = 0;
        for(int i=0; i<10; i++){
            cin  >>  n;
            if(n%2 ==1){
                sum += n;
            }
        }
        cout << "#" <<  tc + 1  <<  " "<<  sum << '\n';
    }
}

