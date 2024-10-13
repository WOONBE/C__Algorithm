#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int x;
int main(){
    First

    int n = 8;
    cin >> x;
    int cnt = 0;

    for(int i=0; i<n ; i++){
        if(x & (1<<i)){
            cnt++;
        }
    }

    cout << cnt << "\n";

}
