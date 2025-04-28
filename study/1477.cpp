#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
int N,M,L,num;
bool visited[1001];
struct Rest{
    int dist;
    int srt_p;
    int ed_p;

};
struct cmp{
    bool operator()(Rest a, Rest b){
        return a.dist < b.dist;
    }
};
priority_queue<Rest,vector<Rest>,cmp> pq;

int main(){
    First;
    cin >> N >> M >> L;
    vector<int> v;
    for(int i=0; i<N; i++){
        cin >> num;
        v.push_back(num);
        visited[num] = true;
    }
    sort(v.begin(),v.end());


    for(int i=0; i<N; i++){
        if(i==0){
            pq.push({v[i],1, v[i]});

        }
        if(i==N-1){
            pq.push({L - v[i], v[i],L});

        }else{
            pq.push({v[i+1] - v[i],v[i],v[i+1]});
        }
    }


    while(M){
        auto cur = pq.top(); pq.pop();
        int srt = cur.srt_p;
        int ed = cur.ed_p;
        int mid = (srt+ed)/2;
//        if(visited[mid]){
//            mid--;
//            if(visited[mid]){
//                mid+=2;
//            }
//        }
        while(visited[mid] && mid > srt) mid--;
        if(mid == srt || visited[mid]){ // 그래도 안되면 오른쪽으로
            mid = (srt + ed) / 2;
            while(visited[mid] && mid < ed) mid++;
        }
        visited[mid] = true;
        pq.push({mid - srt, srt, mid});
        pq.push({ed - mid, mid, ed});
        M--;
    }

    cout << pq.top().dist << "\n";

//    while(!pq.empty()){
//        cout << pq.top().dist << ' ' <<pq.top().srt_p << ' ' << pq.top().ed_p << "\n";
//        pq.pop();
//    }










}