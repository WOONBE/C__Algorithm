#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


vector<pair<int,int> > v;

int N;

//pq에 넣어서 연료 큰 순으로 정리하고, 하나씩 넣음(도착지 전까지)
struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            return a.first > a.second;
        }
        return a.second < b.second;
    }
};


int main(){
    First

    cin >> N;
    int place, fuel;
    int goal, now_fuel;
    for(int i=0; i<N; i++){
        cin >> place >> fuel;
        v.push_back({place,fuel});
    }
    cin >> goal >> now_fuel;

    //예제는 정리되어 있는데 실제로는 아닐듯, 거리순 정렬
    sort(v.begin(), v.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    bool isEnough = true;
    int now_idx = 0;
    int station_cnt = 0;

    while(goal > now_fuel){

        //현재 갈 수 있는 거리에서 넣을수 있는 연료는 다 넣자
        while (now_idx < N && v[now_idx].first <= now_fuel ){
            pq.push(v[now_idx]);
            now_idx ++;
        }

        //pq 비어있으면 도달 불가
        if(pq.empty()){
            cout << -1 <<"\n";
            isEnough = false;
            break;
        }

        now_fuel += pq.top().second;
        pq.pop();

        station_cnt++; //빼면서 횟수 증가


    }
    if(isEnough){
        cout << station_cnt << "\n";
    }
}