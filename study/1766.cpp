#include <iostream>
#include <vector>
#include <queue>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N,M,srt,ed;
int degree[32001];
vector<int> v[100001];
int main(){
    First

    cin >> N >> M;

    for(int i=0; i<M; i++){
        cin >> srt >> ed;
        v[srt].push_back(ed);
        degree[ed]++;
    }

    priority_queue<int,vector<int>,greater<>> pq;

    for(int i=1; i<=N; i++){
        if(degree[i] == 0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        cout << cur << ' ';
        for(auto i : v[cur]){
            degree[i]--;
            if(degree[i] == 0){
                pq.push(i);
            }
        }
    }

}