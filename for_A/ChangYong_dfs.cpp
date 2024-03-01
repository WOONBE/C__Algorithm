//
// Created by 김헌우 on 2024/03/01.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int ans,n,m;
vector<int> v[101];
int visited[101];

void init(){
    ans = 0;
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<101; i++){
        v[i].clear();
    }
}

void input(){
    cin >> n >> m;
    int a,b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b); //간선 간 연결
        v[b].push_back(a);
    }


}

void dfs(int person){
    int nxt = 0;
    for (int i=0; i<v[person].size(); i++){
        nxt = v[person][i];
        if(visited[nxt])
            continue;
        visited[nxt] = 1;
        dfs(nxt);
    }
}

void solve(){
    if (m == 0){
        ans = n;
        return;
    }

    for (int i=1; i<=n; i++){
        if(visited[i]){
            continue;
        }
        visited[i] = 1;
        dfs(i);
        ans++;
    }

}


int main(){
    int t;
    cin >> t;
    for(int tc=1; tc<=t; tc++) {
        init();
        input();
        solve();

        cout << '#' << tc << ' ' << ans << "\n";

    }
    return 0;

}