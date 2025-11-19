#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

string s1,s2;
string ans = "";
vector<char> v;

int main(){
    First
    cin >> s1;
    cin >> s2;

    int s2_len = s2.length();

    for(int i=0; i<s1.length(); i++){
        v.push_back(s1[i]);
        if(v.size() >= s2_len){
            bool is_bomb = true;
            for(int j = 0; j < s2_len; j++){
                if(v[v.size() - s2_len + j] != s2[j]){
                    is_bomb = false;
                    break;
                }
            }
            if(is_bomb){
                v.erase(v.end() - s2_len, v.end());
            }
        }
    }

    for(int i=0; i<v.size(); i++){
        ans += v[i];
    }

    if(ans == ""){
        cout << "FRULA" << "\n";
    }else{
        cout << ans << "\n";
    }
    return 0;
}