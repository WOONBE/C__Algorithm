#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
int N,num;
int main(){
    First
    priority_queue<int,vector<int>, greater<>> pq; //최소힙으로 구현
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> num;
            if(pq.size() < N){
                pq.push(num);
            }
            if(pq.top() < num){
                pq.pop();
                pq.push(num);
            }
        }
    }
    cout << pq.top() << "\n";
}