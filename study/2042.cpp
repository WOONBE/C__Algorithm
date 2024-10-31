#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
#define First ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);


long long a[1000001];
long long d[4000001];
void init(int node, int start, int end){
    if(start == end){
        d[node] = a[start];
        return;
    }

    int mid = (start + end)/2;
    init(node*2,start, mid);
    init(node*2+1,mid+1,end);
    d[node] = d[node*2] + d[node*2+1];

}
long long query(int node, int start, int end, int i, int j){

    if(end < i || start > j){
        return 0;
    }
    if(i<= start && end<=j){
        return d[node];
    }
    int mid = (start+end)/2;


    return query(node*2,start,mid,i,j) + query(node*2+1,mid+1,end,i,j);
}

void update(int node, int start, int end, int i, long long val){
    if(i < start || i>end){
        return;
    }
    if(start==end){
        d[node] = val;
        return;
    }
    int mid = (start+end)/2;
    update(node*2,start,mid,i,val);
    update(node*2+1,mid+1,end,i,val);
    d[node] = d[node*2] + d[node*2+1];

}
int N,M,K;
int main(){
    First
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }
    init(1,1,N);
    M+=K;



    while(M--){
        long long type,x,y;
        cin >> type >> x >> y;
        if(type == 1){
            update(1,1,N,x,y);
        }
        if(type == 2){
            cout << query(1,1,N,x,y) <<"\n";
        }

    }



}