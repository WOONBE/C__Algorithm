#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[10001];
vector<pair<int,pair<int,int>>> graph;
int V,E;
int x,y,dist;
int ans = 0;

int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]); //이부분 리턴 적는거 자꾸 까먹음
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        parent[x] = y;
    }
}

bool isSameParent(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        return false;
    }else{
        return true;
    }
}

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){

    First
    cin >> V >> E;

    for(int i=1; i<=V; i++){
        parent[i] = i;
    }
    for(int i=0; i<E;i++){
        cin >> x >> y >> dist;
        graph.push_back({dist,{x,y}});
    }

    sort(graph.begin(),graph.end());

    for(int i=0; i<graph.size(); i++){
        int start = graph[i].second.first;
        int end = graph[i].second.second;
        if(!isSameParent(start,end)){
            Union(start,end);
            ans += graph[i].first;
        }
    }

    cout << ans << "\n";

    return 0;

}
