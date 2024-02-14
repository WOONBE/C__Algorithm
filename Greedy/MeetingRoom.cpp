//
// Created by 김헌우 on 2024/02/14.
//
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
int n;
std::pair<int,int> p[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> p[i].second >> p[i].first; //정렬할때 편하게 하기 위하여 end time 부터 넣는다
    }
    sort(p,p+n);

    int result = 0;
    int time = 0; //현재 시간

    for(int i=0; i<n; i++){ //배정
        if(time > p[i].second) continue;
        result ++; //이전에 배정한 스케쥴의 끝나는 시간 이후에 다음 스케쥴의 시작시간이 주어질 수 있으면 배정
        time = p[i].first;
    }
    cout << result << "\n";

}
