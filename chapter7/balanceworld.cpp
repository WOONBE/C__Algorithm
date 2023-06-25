//
// Created by 김헌우 on 2023/06/25.
//

#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string s;
        getline(cin,s);
        if(s ==".") break; // .이 오면 작업 종료
        stack<char> S;
        bool isValid = true; //yes or no
        for (auto c : s){
            if(c=='('||c=='[') S.push(c); //in
            else if(c==')'){
                if(S.empty() || S.top() != '('){ // 비었거나 앞에 '('가 없을때 예외처리
                    isValid = false;
                    break;
                }
                S.pop();
            }
            else if(c==']'){
                if(S.empty() || S.top() != '['){
                    isValid = false;
                    break;
                }
                S.pop();
            }
        }
        if(!S.empty()) isValid = false;
        if(isValid) cout << "yes\n";
        else cout << "no\n";
    }
}