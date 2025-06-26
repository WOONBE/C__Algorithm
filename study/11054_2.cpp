#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int N;
int arr[1001];
int dp[1001];
int increase[1001];
int decrease[1001];
int main(){
    First
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    //K이전에 오름차순인 부분의 길이 구하기
    for(int k=0; k<N; k++){
        increase[k] = 1;
        for(int i=0; i<k; i++){
            if(arr[i]< arr[k]){
                increase[k] = max(increase[k],increase[i] + 1);
            }
        }
    }
    //k 이후에 내림차순인 부분의 길이 구하기
    for(int k=N-1; k>=0; k--){
        decrease[k] = 1;
        for(int i=N-1; i>=k; i--){
            if( arr[i] < arr[k]){
                decrease[k] = max(decrease[k],decrease[i] + 1);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<N; i++){
        dp[i] = increase[i] + decrease[i];
        ans = max(dp[i],ans);
    }
    cout << ans-1 << "\n";
}