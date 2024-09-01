//
// Created by 김헌우 on 2024/09/01.
//2503

#include <iostream>
#include <vector>
#include <algorithm>

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
                if(i == j || j== k || k == i)
                    continue;

                bool possible = true;
                for(auto g : v){
                    int guess_num = g.num;
                    int strike = g.strike;
                    int ball = g.ball;

                    int strike_cnt = 0;
                    int ball_cnt = 0;

                    int g1 = guess_num / 100;       // 백의 자리
                    int g2 = (guess_num / 10) % 10; // 십의 자리
                    int g3 = guess_num % 10;        // 일의 자리

                    // 스트라이크 계산
                    if (i == g1) strike_cnt++;
                    if (j == g2) strike_cnt++;
                    if (k == g3) strike_cnt++;

                    // 볼 계산
                    if (i == g2 || i == g3) ball_cnt++;
                    if (j == g1 || j == g3) ball_cnt++;
                    if (k == g1 || k == g2) ball_cnt++;

                    // 주어진 스트라이크, 볼과 일치하지 않으면 불가능한 숫자
                    if (strike_cnt != strike || ball_cnt != ball) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    possible_count++;
                }
            }


            }
        }

    cout << possible_count << "\n";

    return 0;
}


