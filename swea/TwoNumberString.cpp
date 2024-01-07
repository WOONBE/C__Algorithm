//
// Created by 김헌우 on 2023/12/29.
//1959


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T,N,M;
    int a[20],b[20];
    cin >> T;

    for(int tc=1; tc<=T; tc++){
        cin >> N >> M;
        for(int i=0; i<N; i++){
            cin >> a[i];
        }
        for(int i=0; i<M; i++){
            cin >> b[i];
        }
        int max = -9999999;

        if(M > N){
            for(int idx =0; idx< M-N+1; idx++){
                int value = 0;
                for(int i=0; i<N; i++) value += a[i] * b[i+idx];
                if( value > max ) max = value;
            }

        }
            for(int idx =0; idx< N-M+1; idx++){
                int value = 0;
                for(int i=0; i<M; i++) value += a[i+idx] * b[i];
                if( value > max ) max = value;
            }


        cout << '#' << tc << ' ' << max << '\n';
    }
}
