////
//// Created by 김헌우 on 2024/09/02.
////
//#include <iostream>
//#include <cmath>
////다 기본 1로 시작한다고 했을때 +1, +2, +4 등의 순차적으로 더하는 과정에서 생기는 수를 카운트
////헷갈리면 2강 24분부터 다시 보기
//
//using namespace std;
//#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//
//long long a,b;
//int main(){
//
//    First
//
//    cin >> a >> b;
//
//    a-=1;
//    long long a_cnt = a;
//    long long b_cnt = b;
//
//    long long div_num = 0;
//    while(a){
//        a_cnt += a/2 * pow(2,div_num);
//        a = a/2;
//        div_num += 1;
//    }
//    div_num = 0;
//    while (b){
//        b_cnt += b/2 * pow(2,div_num);
//        b = b/2;
//        div_num += 1;
//    }
//    cout << b_cnt - a_cnt << "\n";
//    return 0;
//
//
//
//}

#include <iostream>
#include <cmath>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

long long a, b;

int main() {
    First

    cin >> a >> b;

    a -= 1;

    long long a_cnt = a;
    long long b_cnt = b;

    // Python 코드의 방식 반영
    for (int i = 1; i < 50; i++) {
        long long power_of_2_i = (1LL << i); // 2^i
        long long power_of_2_i_minus_1 = (1LL << (i - 1)); // 2^(i-1)

        a_cnt += (a / power_of_2_i) * (power_of_2_i - power_of_2_i_minus_1);
        b_cnt += (b / power_of_2_i) * (power_of_2_i - power_of_2_i_minus_1);
    }

    cout << b_cnt - a_cnt << "\n";

    return 0;
}

