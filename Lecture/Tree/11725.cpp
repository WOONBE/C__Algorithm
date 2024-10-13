#include <iostream>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N;
vector<vector<int>> v;
int parent[100001];

void dfs(int cur){
    for(auto nxt : v[cur]){
        if(parent[cur] == nxt) continue;

        parent[nxt] = cur;
        dfs(nxt);
    }
}


int main(){
    First

    cin >> N;


    v.resize(N+1);

    for(int i=0; i<N-1; i++){ //입력부분에서 문제
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);

    for(int i = 2; i <= N; i++) cout << parent[i] << '\n';



}