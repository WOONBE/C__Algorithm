#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,K;
int calculate(int n){
    int cnt = 0;
    while(n){
        if(n%2 == 1) cnt++;
        n /=2;
    }
    return cnt;
}
int main(){
    First

    cin >> N >> K;
    int cnt = 0;
    while(true){
        if(K < calculate(N)){
            cnt++;
            N++;
        }else{
            break;
        }
    }
    cout << cnt << "\n";
}