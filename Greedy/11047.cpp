#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,money;
vector<int> v(11); //범위 명시 해줘야 돌아감

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> money;

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int cnt = 0;

    sort(v.begin(),v.end(), greater<int>());

    for(auto coin : v){
        if(coin == 0) continue; //처리 안해주면 division error
            cnt += money/coin;
            money %= coin;

    }

    cout << cnt << "\n";
}
