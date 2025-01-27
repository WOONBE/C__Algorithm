#include <iostream>
#include <vector>
#include <queue>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,S;
vector<int> v(10001);
vector<int> prefix(10001);
priority_queue<int,vector<int>,greater<>> pq;
int main(){
    First

    cin >> N >> S;

    for(int i=0; i<N; i++){
        cin >> v[i];

    }
    prefix[0] = v[0];

    for(int i=1; i<N; i++){
        prefix[i] = prefix[i-1] + v[i];
    }

    for(int i=N-1; i>=0; i--){
        if(prefix[i] >=S){
            pq.push(i + 1);
        }
        for(int j=i-1; j>=0; j--){
            if(prefix[i] - prefix[j] >= S){
                pq.push(i-j);
                break;
            }
        }
    }
    if(pq.empty()){
        cout << 0 << "\n";
    }else{
        cout << pq.top() << "\n";
    }









}