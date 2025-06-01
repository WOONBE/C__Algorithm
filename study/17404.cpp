#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Mx 987654321
int N;
int result = 987654321;

int dp[1001][3]; //i번을 j로 칠했을 때의 최소값
int main(){
    First

    cin >> N;

    vector<vector<int>> v(N, vector<int>(3,0));

    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> v[i][j];
        }
    }

    for(int first=0; first<3; first++){

        for(int i = 0; i < N; i++){
            for(int j = 0; j < 3; j++){
                dp[i][j] = Mx;
            }
        }

        dp[0][first] = v[0][first];

        for(int i=1; i<N; i++){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + v[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + v[i][1];
            dp[i][2] = min(dp[i-1][1],dp[i-1][0]) + v[i][2];
        }

        for(int last=0; last<3; last++){
            if(first==last) continue;
            else{
                result = min(result, dp[N-1][last]);
            }
        }

    }

    cout << result << "\n";


}