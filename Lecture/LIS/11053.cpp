#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> arr;
int N;
int main(){
    First

    cin >> N;
    arr.resize(N,0);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int dp[N];

    //이중으로 도는데
    for(int i=0; i<N; i++){
        //일단 자기 값에서 1로 표시해주고
        dp[i] = 1;
        //왼쪽부분만 보면 된다
        for(int j=0; j<i; j++){
            //j=i-1; j>=0; j--로 처음에 풀긴했음
            //앞부분의 dp배열에서의 값에 현재값을 더한 값이랑 지금 현재 1인 값이랑 비교해서 더 큰값으로
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int answer = *max_element(dp, dp+N);

    cout << answer;


}