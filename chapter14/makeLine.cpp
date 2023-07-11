//
// Created by 김헌우 on 2023/07/11.
//2170, 스윕 라인 알고리즘, 정렬시킨 후에 다음 길이의 시작점이 기존 길이의 도착점보다 앞이면 같은 line + 추가 도착점이 기존 도착점보다 작으면 갱신 x(중복이다)

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
vector<pair<int,int>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll start, end, answer=0;
    cin >> n;


    for(int i=0; i<n; i++){
        cin >> start >> end;
//        if(start>end)
//            swap(start,end);
        v.push_back(make_pair(start,end));
    }
    sort(v.begin(),v.end()); //front 아님, 어차피 앞에 인덱스 기준으로 자동으로 sort 해줌

    start = v[0].first; end = v[0].second;

    for(int i=1 ; i<n ; i++) {
        int s = v[i].first, e = v[i].second;
        if(end>=s) {
            if(end<e) {
                end = e;
            }
        } else {
            answer += end-start;
            start = s, end = e;
        }
    }
    answer += end-start;
    cout << answer << "\n";

}

