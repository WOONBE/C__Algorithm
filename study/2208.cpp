#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,M,num,ans;
vector<int> v(100001);
vector<int> prefix(100001);
int main(){
    First

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        cin >> num;
        v[i] = num;
        prefix[i] = prefix[i-1] + v[i];
    }

    int val = 0;

    ans = 0;

    for(int i=M; i<=N; i++){
        ans = max(ans, prefix[i] - min(val, prefix[i-M]));
        val = min(prefix[i - M], val);
    }

    cout << ans;
















};