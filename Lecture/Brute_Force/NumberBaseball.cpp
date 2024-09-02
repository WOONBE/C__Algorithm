//
// Created by 김헌우 on 2024/09/01.
//2503

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct game{
    int num;
    int strike;
    int ball;
};

bool cmp(game a, game b){
    if(a.num == b.num){
        return a.strike > b.strike;
    }
    return a.num > b.num;
}
int num;
vector<game> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;
    for(int i=0; i<num; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }

    int possible_count = 0;

    for(int i=1; i<=9; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=9; k++){
                int count = 0;
                if(i == j || j== k || k == i)
                    continue;



                for(auto g : v){
                    int guess_num = g.num;
                    int strike = g.strike;
                    int ball = g.ball;

                    int strike_cnt = 0;
                    int ball_cnt = 0;

                    string str_num = to_string(guess_num);

                    if(int(str_num[0]) == i){
                        strike_cnt++;
                    }
                    if(int(str_num[1]) == j){
                        strike_cnt++;
                    }
                    if(int(str_num[2]) == k){
                        strike_cnt++;
                    }
                    if(i == int(str_num[1]) || i == int(str_num[2])){
                        ball_cnt++;
                    }
                    if(j == int(str_num[0]) || j == int(str_num[2])){
                        ball_cnt++;
                    }
                    if(k == int(str_num[0]) || k == int(str_num[1])){
                        ball_cnt++;
                    }

                    if(strike == strike_cnt && ball == ball_cnt){
                        count++;
                    }

                }
            }


            }
        }

//    cout <<  << "\n";

    return 0;
}


