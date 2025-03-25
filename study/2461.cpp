#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int> v[1001];
int idx[1001]; //각 반의 대표 위치 지정
int N,M,num;
long long ans = 9987654321;
int main(){
    First

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> num;
            v[i].push_back(num);
        }
        sort(v[i].begin(),v[i].end());
    }

    while(true){
        int max_val = 0;
        long long min_val = 9999999999;
        int max_idx = 0;
        int min_idx = 0;


        for(int i=0; i<N; i++){
            if(v[i][idx[i]] < min_val){
                min_val = v[i][idx[i]];
                min_idx = i;
            }
            if(v[i][idx[i]] > max_val){
                max_val = v[i][idx[i]];
                max_idx = i;
            }
        }

        ans = min(max_val - min_val,ans);

        idx[min_idx]++;
        if(idx[min_idx] == M){
            break;
        }
    }

    cout << ans << "\n";

}