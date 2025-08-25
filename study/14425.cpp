#include <bits/stdc++.h>
using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int N,M;
vector<string> s;
string a;
int main(){
    First

    cin >> N >> M;
    s.assign(N+1,"");
    for(int i=0; i<N; i++){
        cin >> s[i];
    }

    sort(s.begin(),s.end());
    int cnt = 0;
    while(M--){
        cin >> a;
        if(binary_search(s.begin(),s.end(),a)) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}