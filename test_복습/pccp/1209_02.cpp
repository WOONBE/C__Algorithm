#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void processPills(int n, int m) {
    // 우선순위 큐를 사용해 약 봉지 길이를 관리 (최소 힙)
    priority_queue<int, vector<int>,greater<int>> pq;


    pq.push(n);
    //7 4 2 1 1
    for(int i=0; i<m; i++){
        n = pq.top();

        while(pq.top() != 1){
            if(n % 2 == 0){
                pq.pop();
                n /= 2;
                pq.push(n);
                pq.push(n);
            }else {
                pq.pop();
                n /= 2;
                pq.push(n + 1);
                pq.push(n);
            }
        }
        if(pq.top() == 1){
            pq.pop();
        }
    }

    vector<int>  v;
    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }

    sort(v.begin(), v.end(), greater<int>());

    for(auto i : v){
        cout << i << ' ';
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    processPills(n, m);
    return 0;
}
