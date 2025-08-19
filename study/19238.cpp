#include <bits/stdc++.h>
using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

struct people{
    int dist;
    int srt_x;
    int srt_y;
    int dest_x;
    int dest_y;
};
int N,M,oil,taxi_x,taxi_y,a,b,c,d;
int arr[21][21];
int visited[21][21];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
long long INF = 987654321;
pair<int,pair<int,int>> cur; //남은 오일량, 현재 x,y;
bool OOB(int x, int y){
    return x>=1 && y>=1 && x<=N && y<=N;
}
int calc_dist(int cur_x, int cur_y, int p_x,int p_y){
    queue<pair<int,pair<int,int>>> q; //dist,x,y
    memset(visited,-1,sizeof(visited));
    q.push({0,{cur_x,cur_y}});
    visited[cur_x][cur_y] = 1;
    while(!q.empty()){
        auto cur = q.front();q.pop();
        int x = cur.second.first;
        int y = cur.second.second;
        int dist = cur.first;
        if(x == p_x && y == p_y) return dist;

        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(!OOB(nx,ny)) continue;
            if(visited[nx][ny] != -1) continue;
            if(arr[nx][ny] == 1) continue;
            visited[nx][ny] =1;
            q.push({dist+1,{nx,ny}});
        }
    }
    return INF;
}
struct cmp{
    bool operator()(people a, people b){
        if(a.dist == b.dist){
            if(a.srt_x == b.srt_x){
                return a.srt_y > b.srt_y;
            }
            return a.srt_x > b.srt_x;
        }
        return a.dist > b.dist;
    }
};
int main(){

    cin >> N >> M >> oil;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }
    cin >> taxi_x >> taxi_y;
    cur = {oil,{taxi_x,taxi_y}};
    priority_queue<people,vector<people>,cmp> pq;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c >> d;
        int t_to_p = calc_dist(cur.second.first,cur.second.second,a,b);
        pq.push({t_to_p,a,b,c,d});
    }
    int ans_oil = -1;
    int oil_cnt = 0;
    while(true){
        if(pq.empty() || oil_cnt == M){
            ans_oil = cur.first;
            break;
        }
        auto cur_p = pq.top(); pq.pop();
        int cur_dist = cur_p.dist;
        int cur_srt_x = cur_p.srt_x;
        int cur_srt_y = cur_p.srt_y;

        //cout << "now_people" << cur_srt_x << ' ' << cur_srt_y <<"\n";
        int cur_dest_x = cur_p.dest_x;
        int cur_dest_y = cur_p.dest_y;

        if(cur.first <cur_dist || cur.first <= 0){
            break;
        }

        cur.first -= cur_dist;

        if(cur.first < calc_dist(cur_srt_x,cur_srt_y,cur_dest_x,cur_dest_y) ||calc_dist(cur_srt_x,cur_srt_y,cur_dest_x,cur_dest_y) == INF){
            break;
        }
        oil_cnt++;
        cur.first += calc_dist(cur_srt_x,cur_srt_y,cur_dest_x,cur_dest_y);
        cur = {cur.first,{cur_dest_x,cur_dest_y}};
        //pq에 최단거리 다시 넣는 작업 필요
        vector<people> v;
        while(!pq.empty()){
            auto pq_top = pq.top(); pq.pop();
            auto pq_top_srt_x = pq_top.srt_x;
            auto pq_top_srt_y = pq_top.srt_y;
            auto pq_top_dest_x = pq_top.dest_x;
            auto pq_top_dest_y = pq_top.dest_y;
            int pq_dist = calc_dist(cur.second.first,cur.second.second,pq_top_srt_x,pq_top_srt_y);
            v.push_back({pq_dist,pq_top_srt_x,pq_top_srt_y,pq_top_dest_x,pq_top_dest_y});
        }
        for(auto i : v){
            pq.push({i.dist,i.srt_x,i.srt_y,i.dest_x,i.dest_y});
        }
    }
    cout << ans_oil << "\n";


}