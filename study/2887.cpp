#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int parent[1000001];
vector<pair<int,int>> v[3];
vector<pair<int,pair<int,int>>> way; //i와 i+1 사이 거리, 좌표 2개
int N,ans;

int Find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);

}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) {
        parent[a] = b;
    }

}
bool isSame(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b){
        return false;
    }else{
        return true;
    }
}


int main(){
    First

    cin >> N;
    int x,y,z;
    for(int i=0; i<N; i++){
        parent[i] = i;
        cin >> x >> y >> z;
        v[0].push_back({x,i});
        v[1].push_back({y,i});
        v[2].push_back({z,i});
    }

    for(int i=0; i<3; i++){
        sort(v[i].begin(),v[i].end());
    }

    for(int i=0; i<N-1; i++){
        way.push_back({abs(v[0][i].first - v[0][i+1].first),{v[0][i].second,v[0][i+1].second} });
        way.push_back({abs(v[1][i].first - v[1][i+1].first),{v[1][i].second,v[1][i+1].second} });
        way.push_back({abs(v[2][i].first - v[2][i+1].first),{v[2][i].second,v[2][i+1].second} });
    }
    sort(way.begin(),way.end());

    for(int i=0; i<way.size(); i++){
        if(!isSame(way[i].second.first, way[i].second.second)){
            ans += way[i].first;
            Union(way[i].second.first, way[i].second.second);
        }
    }

    cout << ans << "\n";

}