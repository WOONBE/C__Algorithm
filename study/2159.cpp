#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//10만 배열이니까 nlogn 필요
//pq 만들어서 거리순으로 계산하고 가장 앞에거 빼내고 pq 초기화하는 방식?
long long N;
long long startX, startY;
long long x,y;
queue<pair<long long ,long long >> q;
long long total_dist;

struct point{
    long long x;
    long long y;
    long long dist;

};

struct cmp{
    bool operator()(point a, point b){
        return a.dist > b.dist;
    }
};
int main(){
    First

    cin >> N;
    cin >> startX >> startY;
    for(long long i=0; i<N; i++){
        cin >> x >> y;
        q.push({x,y});
    }

    long long vis_cnt = 0;
    //방문할때마다 카운트 증가

    while(true){
        if(vis_cnt == N){
            break;
        }

        priority_queue<point, vector<point>, cmp> pq;
        queue<pair<long long , long long >> q2; //임시로 넣어둘 q
        int min_len =987654321;
        //q에서 빼면서 길이 계산하고, 가장 짧은 길이면 pq에 갱신해서 넣기
        for(long long i=0; i<q.size(); i++){
            auto cur = q.front(); q.pop();
            long long x = cur.first;
            long long y = cur.second;
            long long dist = abs(startX - x) + abs(startY - y);
            if(dist < min_len){
                min_len = dist;
                pq.push({x,y,dist});
            }else{
                q2.push({x,y});
            }
        }
        if(!pq.empty()){
            auto cur = pq.top();pq.pop();
            startX = cur.x;
            startY = cur.y;
            total_dist += cur.dist;
            vis_cnt++;
            cout << startX << ' ' << startY << "\n";
        }
        while(!pq.empty()){
            auto cur = pq.top();pq.pop();
            q.push({cur.x,cur.y});
        }
        while(!q2.empty()){
            auto cur = q2.front(); q2.pop();
            q.push({cur.first,cur.second});
        }
    }
    cout << total_dist << "\n";


}