#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int N;
vector<int> v;
long long dp[5001][5001];
int main()
{
    First
    //정렬된 순서대로 출력
    //1,2,3 순서
    //3,1,2
    //1,2,3
    //3,2,1
    //5,6,4(ai < aj && ai > ak)는 불가
    //불가능한 케이스 찾아서 다 출력

    cin >> N;
    v.resize(N,0);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    //j > k인 부분 체크하기 위하여 사용
    //j가 k보다 큰 경우의 수 저장
    for(int i=0; i<N; i++){
        for(int j=N-1; j>i;j--){ //실수
            if(v[i] > v[j]){
                dp[i][j] = dp[i][j+1] + 1;
            }
            else{
                dp[i][j] = dp[i][j+1];
            }
        }
    }

    long long ans = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(v[i] <v[j]){
                ans += dp[i][j];
            }
        }
    }
    cout << ans << "\n";

        //    int cnt = 0;
//    for(int i=0; i<N; i++){
//        for(int j=i+1; j<N; j++){
//            for(int k = j+1; k<N; k++){
//                if(v[i] < v[j] && v[i] > v[k]){
//                    cnt++;
//                }
//            }
//        }
//    }
//    cout << cnt << "\n";

    return 0;
}