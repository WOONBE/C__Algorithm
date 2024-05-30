#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    sort(s.begin(), s.end(), greater<>());
    int sum = 0;

    //끝자리가 0에 각자리 합이 3이 되어야함
    if(s[s.size()-1] != '0') cout << -1; //str로 해줘야함
    else{
        for(auto i : s){
            sum += i-'0';
        }
        if(sum % 3 == 0){
            cout << s;
        }else{
            cout << -1;
        }
    }
}
