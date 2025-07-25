#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int N,M,X,Y,K;
int dp[101][101];
vector<pair<int,int>> graph[101]; //노드, 개수
int degree[101];
vector<int> basic;
int main(){
    First
    cin >> N;
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> X >> Y >> K;
        graph[Y].push_back({X,K});
        degree[X]++;
    }

    queue<int> q;//위상정렬을 위한 큐
    for(int i=1; i<=N; i++){
        if(!degree[i]){
            q.push(i);
            dp[i][i] = 1;
            basic.push_back(i);
        }
    }
    while(!q.empty()){
        auto cur_node = q.front(); q.pop();

        for(auto i : graph[cur_node]){

            for(int j=1; j<=N; j++){
                dp[i.first][j] += dp[cur_node][j] * i.second;
            }
            degree[i.first]--;
            if(!degree[i.first]) q.push(i.first);
        }
    }
    sort(basic.begin(),basic.end());
    for(auto i : basic){
        cout << i << ' ' << dp[N][i] << "\n";
    }
}