#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

vector<pair<int,int>> seat;
int N,x,y;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }

};

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> computer; //끝나는 시간, 컴퓨터 번호
priority_queue<int, vector<int>, greater<>> empty_seats;
int main(){
    First
    cin >> N;

    vector<int> seat_cnt(N+1,0);
    for(int i=0; i<N; i++){
        cin >> x >> y;
        pq.push({x,y});
    }
    int com_cnt = 0;
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int cur_srt = cur.first;
        int cur_ed = cur.second;

        while(!computer.empty() && computer.top().first < cur_srt){
            int can_seat_num = computer.top().second; computer.pop();
            empty_seats.push(can_seat_num);
        }
        int cur_seat;
        //비어있는 자리가 있으면
        if(!empty_seats.empty()){
            cur_seat = empty_seats.top(); empty_seats.pop();
        }else{
            com_cnt++;
            cur_seat = com_cnt;
        }

        seat_cnt[cur_seat]++;
        computer.push({cur_ed,cur_seat});
    }

    cout << com_cnt << "\n";
    for(int i=1; i<=com_cnt; i++){
        cout << seat_cnt[i] << ' ';
    }
    cout << "\n";
    return 0;
}