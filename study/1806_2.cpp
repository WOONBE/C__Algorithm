#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int N,S;
vector<int> v;
int main(){
    First
    cin >> N >> S;
    v.assign(N,0);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    int left = 0;
    int right = 0;
    int sum = 0;
    int len = 100001;

    while(right < N){
        sum += v[right];

        while(sum >= S){
            len = min(len, right - left + 1);
            sum -= v[left];
            left++;
        }
        right++;
    }
    if(len == 100001){
        cout << 0 << "\n";
        return 0;
    }
    cout << len << "\n";
}