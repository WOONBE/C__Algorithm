//
// Created by 김헌우 on 2024/09/08.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int T;
int N, height;
int ans;
int main(){
    First

    //입력
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> N;
        vector<int> v(N,0);
        for(int j = 0; j<N; j++){
            cin >> height;
            v[j] = height;
        }

        sort(v.begin(),v.end());


        int mx_height = v[N-1];


        int even = 0; //짝수
        int odd = 0; //홀수
        //차이만큼 필요한 2랑 1 개수 구하기
        for(int k=0; k<N; k++){

            int sub = mx_height - v[k];


            if(sub == 0) continue; //여기 부등호 하나 안적어서 터졌던 거였음

            even += sub / 2;
            odd += sub % 2;
        }

        while(even-odd > 1){
            even--;
            odd++;
            odd++;
        }

        if(odd > even){
            ans = odd * 2 -1;
        }
        else if(even > odd){
            ans = even * 2;
        }
        else{

            ans = even + odd;
        }

        cout << '#' << i << ' ' << ans << "\n";



    }

}
