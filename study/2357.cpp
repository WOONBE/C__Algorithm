#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N,M,a,b;
vector<long long> v;
vector<pair<long long,long long>> d; //앞에 최소, 뒤에 최대값

pair<long long, long long> init(int node,int st,int ed){
    if(st==ed){
        return d[node] = {v[st],v[st]};
    }
    int mid = (st+ed)/2;
    pair<long long, long long> l_idx = init(node * 2,st,mid);
    pair<long long, long long> r_idx = init(node * 2 + 1,mid+1,ed);
    return d[node] = {min(l_idx.first,r_idx.first), max(l_idx.second,r_idx.second)};
}
pair<long long, long long> query(int node, int st, int ed, int l, int r){
    if(ed < l || r<st){
        return {LONG_MAX,LONG_MIN}; //이 부분 수정
    }
    if(l<=st && ed <=r){
        return d[node];
    }
    int mid = (st+ed)/2;

    pair<long long, long long> l_idx = query(node * 2,st,mid,l,r);
    pair<long long, long long> r_idx = query(node * 2 + 1,mid+1,ed,l,r);
    return {min(l_idx.first,r_idx.first), max(l_idx.second,r_idx.second)};// 여기 갱신 필요없음
}



int main(){
    First
    cin >> N >> M;

    v.assign(N,0);
    d.assign(4*N,{0,0});
    for(int i=0; i<N; i++){
        cin >> v[i];
    }


    init(1,0,N-1);

    for(int i=0; i<M; i++){
        cin >> a >> b; //a-1,b-1로 쿼리 날려야함
        pair<long,long> ans = query(1,0,N-1,a-1,b-1);
        cout << ans.first << ' ' << ans.second << "\n";
    }

}