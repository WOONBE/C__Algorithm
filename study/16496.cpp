#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int N;
string s = "";
typedef unsigned long long ll;
bool cmp(string a, string b){
    return a+b > b+a;
}
vector<string> v;
int main(){
    First
    cin >> N;
    v.assign(N,"");

    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),cmp);

    if(v[0] == "0"){
        cout << 0 << "\n";
        return 0;
    }
    for(int i=0; i<N; i++){
        s += v[i];
    }
    cout << s << "\n";
}