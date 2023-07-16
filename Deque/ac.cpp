//
// Created by 김헌우 on 2023/07/01.
//isdigit 활용(자력솔 실패), reverse함수 사용시 타임아웃

#include "bits/stdc++.h"
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin >> t;

    while(t--) {
        string order;
        int s = {};//받은 배열에서 숫자만 저장
        string arr = {}; //
        cin >> order;
        cin >> n;
        cin >> arr; //받는 배열

        deque<int> Dq;
        bool reverse = false, error = false;
        for (int i = 0; i < arr.size(); i++) { //deque에 숫자만 입력받음
            if (isdigit(arr[i])) {
                Dq.push_back(arr[i]);
            }

        }
        for (auto c: order) {
            if (c == 'R') {
                if (Dq.empty()) error = true;
                std::reverse(Dq.begin(), Dq.end());
                reverse = true;

            } else if (c == 'D') {
                if (Dq.empty()) error = true;
                Dq.pop_front();
            }

        }
        cout << '[';
        if (error) {
            for (int i = 0; i < Dq.size(); i++) {
                cout << Dq.front() << ",";
                Dq.pop_front();

            }
            cout << ']';

        }else{
            cout << error <<"\n";}
    }

}