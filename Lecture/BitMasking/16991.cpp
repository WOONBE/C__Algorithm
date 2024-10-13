#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1e9;

int N;
vector<pair<double, double>> v;
double arr[16][16];
double dp[16][1<<16];
int full;

double calculate_dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));

}
double dfs(int cur, int state){
    if(state == full){
        if(arr[cur][0]) return arr[cur][0];
        else{
            return INF;
        }
    }

    //이거 -1로 초기화해서 비교하니 nan(memset은 int쓸때만)
    if(dp[cur][state] != -1) return dp[cur][state];

    dp[cur][state] = INF;
    for(int i=0; i<N; i++){
        if(state & (1<<i)) continue;
//        if(arr[cur][i] == 0) continue; //이부분도 고려 필요 x
        dp[cur][state] = min(dp[cur][state], dfs(i, state | (1<<i)) + arr[cur][i]);
    }
    return dp[cur][state];

}
int main(){
    First

    cin >> N;
    v.resize(N);
    //memset에서 터짐
//    memset(dp,3.0,sizeof(dp));
    full = (1<<N) - 1;

    for (int i = 0; i < N; ++i) {
        for(int j=0; j<(1<<N); j++){
            dp[i][j] = -1;
        }
    }

//
//    for (int i = 0; i < N; ++i) {
//        for(int j=0; j<(1<<N); j++){
//            cout << dp[i][j] << ' ';
//        }
//        cout << "\n";
//    }

    for(int i=0; i<N; i++){
        cin >> v[i].first >> v[i].second;
    }

    //테이블부터 생성
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            double dist = calculate_dist(v[i].first,v[i].second, v[j].first, v[j].second);
            arr[i][j] = dist;

        }
    }
//    for(int i=0; i<N; i++){
//        for(int j=0; j<N; j++){
//            cout << arr[i][j] << ' ';
//        }cout << "\n";
//    }

    //이후는 기존 외판원 문제와 동일
    double result =  dfs(0, 1);

    cout << fixed << setprecision(6) << result << "\n";

}
