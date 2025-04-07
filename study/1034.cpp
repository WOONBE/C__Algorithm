#include <iostream>
#include <algorithm>
#include <cstring>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,M,K,ans;
string arr[51];


int main(){
    First
    cin >> N >> M;


    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    cin >> K;

    for(int i=0; i<N; i++){
        int zero_cnt = 0;

        for(int j=0; j<M; j++){
            if(arr[i][j] == '0'){
                zero_cnt++;
            }
        }

        int sum = 0;
        if(zero_cnt <= K && zero_cnt % 2 == K % 2){
            for(int j = 0; j<N; j++){
                if(arr[i] == arr[j]){
                    sum++;
                }

            }
        }
        ans = max(ans,sum);
    }
    cout << ans << "\n";
}