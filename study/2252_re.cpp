#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int> adj[32001];
int degree[32001];
int N,M;
int main(){
    First;

    cin >> N >> M;
    int start,end;
    for(int i=0; i<M; i++){
        cin >> start >> end;
        adj[start].push_back(end);
        degree[end]++;
    }
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto i : adj[cur]){
            int x = i;
            degree[x]--;

            if(degree[x] == 0){
                q.push(x);
            }
        }
    }

}

