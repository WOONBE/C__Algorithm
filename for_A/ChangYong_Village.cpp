
#include <iostream>
#include <algorithm>

using namespace std;
int n, m, ans;
int parent[101];


int find(int tar){
    if(tar == parent[tar]){
        return tar;
    }

    int ret = find(parent[tar]);
    parent[tar] = ret; //
    return ret; //여기 tar로 했다 계속 터짐
}

void set_union(int a, int b){
    int t1 = find(a);
    int t2 = find(b);
    if(t1 == t2){ //같으면 무시
        return;
    }
    parent[t2] = t1; //다르면 연결

}

void init(){
    ans = 0;
}


void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){ //수정
        parent[i] = i;
    }
    int a,b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        set_union(a,b);
    }

}

void solve(){
    for(int i=1; i<=n; i++){
        if(i == find(i)){ //자신이 부모면 cnt 추가
            ans += 1;
        }
    }

}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        init();
        input();
        solve();

        cout << '#' << tc << ' ' << ans << "\n";

    }


}


