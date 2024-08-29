//
// Created by 김헌우 on 2024/08/29.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

//정렬을 위하여 선언
struct Cell{
    int x;
    int y;

};
//우선순위 큐에 넣을때 사용
struct CMP{
    bool operator()(Cell a, Cell b){
        return a.y > b.y; //y 기준 오름차순 정렬
    }
};

//정렬 시킬때 사용
bool cmp(Cell a, Cell b){
    if(a.x == b.x){
        return a.y > b.y; //y 기준 내림차순 정렬
    }
    return a.x > b.x; //x 기준 내림차순 정렬

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<Cell, vector<Cell>, CMP> q;
    vector<Cell> v;

    vector<tuple<int,int,int>> v5;




    for(int i=0; i<10; i++){
        q.push({1,i});
    }
    for(int i=0; i<10; i++){
        v.push_back({i+1,i});
        v.push_back({i,i+1});
    }

    sort(v.begin(),v.end(), cmp);


    while(!q.empty()){
        Cell a = q.top(); q.pop();
        cout << a.x << ", " << a.y << endl;

    }
    for(auto i : v){
        cout << i.x << "," << i.y << "\n";
     }
    vector<int> v1[100];
    vector<int> v2(200);





}
