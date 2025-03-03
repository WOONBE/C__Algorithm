#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N,L;
vector<int> v(5000001);
deque<pair<int,int>> dq; //값, 인덱스 값을 저장
int main(){
    First

    cin >> N >> L;

    for(int i=1; i<=N; i++){
        cin >> v[i];
    }


    for(int i=1; i<=N; i++){
        if(!dq.empty()){
            if(dq.front().second < i-L+1){
                dq.pop_front();
            }
        }
        while(!dq.empty() && dq.back().first > v[i]){
            dq.pop_back();
        }
        dq.push_back({v[i],i});
        cout << dq.front().first << ' ';

    }
    cout << "\n";
}