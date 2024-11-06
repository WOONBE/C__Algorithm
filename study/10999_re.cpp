#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

long long a[1000001];
long long d[4000001];
long long lazy[4000001];
int N,M,K;

void init(int node, int start, int end){
    if(start == end){
        d[node] = a[start];
        return;
    }
    int mid = (start+end)/2; //와 실수
    init(node*2,start,mid);
    init(node*2+1,mid+1,end);
    d[node] = d[node*2] + d[node*2+1];

}
void lazy_init(int node, int start, int end){
    if(lazy[node] != 0){
        d[node] += (end-start+1) * lazy[node];
        if(start != end){
            //이부분 실수
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

long long query(int node, int start, int end, int i, int j){
    lazy_init(node,start,end);
    if(end < i || j < start){
        return 0;
    }
    if(i<=start && end <= j){
        return d[node];
    }
    int mid = (start+end)/2;

    return query(node*2,start,mid,i,j) + query(node*2+1,mid+1,end,i,j);

}

void update(int node, int start, int end, int i, int j, long long val){
    lazy_init(node,start,end);
    if(end < i || j<start){
        return;
    }
    //이 부분 구현이 헷갈림
    if(i<=start && end <= j){
        d[node] += (end-start+1) * val;
        if(start != end){
            //이부분 실수
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, i,j,val);
    update(node*2+1,mid+1,end,i,j,val);
    d[node] = d[node*2] + d[node*2+1];
}


int main(){
    First
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){ //1부터 초기화
        cin >> a[i];
    }
    M+=K;
    init(1,1,N); //init 안해줬음

    while(M--){
        int num;
        cin >> num;
        if(num == 1){
            int b,c;
            long long dist;
            cin >> b >> c >> dist;
            update(1,1,N,b,c,dist);
        }
        else{
            int b,c;
            cin >> b >> c;
            cout << query(1,1,N,b,c) << "\n"; //줄바꿈 x

        }
    }




}