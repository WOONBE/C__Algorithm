#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int N,num;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b;
        }
        return abs(a) > abs(b);
    }
};
int main(){
    First
    cin >> N;
    priority_queue<int,vector<int>,cmp> pq;
    while(N--){
        cin >> num;
        if(num == 0){
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }else{
                cout << 0 << "\n";
            }
        }else{
            pq.push(num);
        }
    }
    return 0;
}