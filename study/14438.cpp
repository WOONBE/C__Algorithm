#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
int N,M,num,first,second;
vector<ll> v;
vector<ll> d;
ll init(int node, int srt, int ed){
    if(srt==ed){
        return d[node] = v[srt];
    }
    int mid = (srt+ed)/2;
    ll l_val = init(node*2,srt,mid);
    ll r_val = init(node*2+1,mid+1,ed);
    return d[node] = min(l_val,r_val);
}

ll query(int node, int srt, int ed, int left, int right){
    if(ed < left || right < srt){
        return -1;
    }
    if(left<=srt && ed <=right){
        return d[node];
    }
    int mid = (srt+ed)/2;
    ll l_val = query(node*2, srt,mid,left,right);
    ll r_val = query(node*2+1,mid+1,ed,left,right);

    if(l_val == -1){
        return r_val;
    }
    else if(r_val == -1){
        return l_val;
    }else{
        return min(l_val,r_val);
    }

}

void change_val(int node, int srt, int ed, int idx, int val){
    if(srt == ed){
        v[idx] = val;
        d[node] = val;
        return;
    }
    int mid = (srt+ed)/2;

    if(idx <=mid){
        change_val(node*2,srt,mid,idx,val);
    }else if(idx > mid){
        change_val(node*2+1,mid+1,ed,idx,val);
    }
    d[node] = min(d[node*2],d[node*2+1]);
}

int main(){

    First
    cin >> N;
    v.assign(N,0);
    d.assign(4*N,0);

    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    init(1,0,N-1);

    cin >> M;

    for(int i=0; i<M; i++){
        cin >> num >> first >> second;
        if(num ==1){
            change_val(1,0,N-1,first-1,second);

        }else if(num == 2){
            cout << query(1,0,N-1,first-1,second-1) << "\n";
        }
    }
}