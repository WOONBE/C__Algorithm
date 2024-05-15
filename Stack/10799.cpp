#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>


using namespace std;

string s;
int ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    stack<char> stk;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') stk.push(s[i]);
        else{
            if(s[i-1]=='('){
                stk.pop();
                ans += stk.size();
            }
            else{
                stk.pop();
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
