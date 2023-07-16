//
// Created by 김헌우 on 2023/06/24.
//
#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);


    queue<int> S;
    int n;
    cin >> n;

    while(n--){ // n번 반복
        string c;
        cin >> c;
        if(c=="push"){
            int t;
            cin >> t;
            S.push(t);
        }
        else if(c=="pop"){
            if(S.empty()) cout << -1 << '\n';
            else{
                cout << S.front() << '\n';
                S.pop();
            }
        }
        else if(c=="size")
            cout << S.size() << '\n';
        else if(c=="empty")
            cout << S.empty() << '\n';
        else if(c=="front") {
            if (S.empty()) cout << -1 << '\n';
            else cout << S.front() << '\n';
        }

        else{ //back
            if(S.empty()) cout << -1 << '\n';
            else cout << S.back() << '\n';
        }
    }
}



