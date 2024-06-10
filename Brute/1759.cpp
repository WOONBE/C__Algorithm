#include <iostream>
#include <algorithm>
using namespace std;

vector<char> v;
vector<char> code;
int L,C;

bool check(){
    int cnt = 0;
    for(int i=0; i<L; i++){
        if(code[i] == 'a'||
            code[i] == 'e'||
            code[i] == 'i'||
            code[i] == 'o'||
            code[i] == 'u'
        )
            cnt++;
    }
    if(cnt >= 1 && L-cnt >=2) return true;
    return false;
}

void dfs(int num){

    if(int(code.size()) == L){
        if(check()){
            for(int i=0; i<L; i++){
                cout << code[i];
            }
            cout << "\n";
        }
        return;
    }
    for(int i=num; i<C; i++){
        code.push_back(v[i]);
        dfs(i+1);
        code.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;

    for(int i=0; i<C; i++){
        char c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end()); //먼저 sort 해놓는게 좋음
    dfs(0);
}
