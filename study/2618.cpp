#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio()

int N,W;

vector<pair<int,int>> point;
int dp[1001][1001];//police1이 a, police2가 b에 있을때의 최소 거리

int cal_dist(int x, int y,int x1, int y1){
    return abs(x-x1) + abs(y-y1);
}

int cal_min_dist(int police1, int police2){
    if(police1 == W || police2 == W){
        return 0;
    }
    if(dp[police1][police2] != -1) return dp[police1][police2];
    int nxt_idx = max(police1,police2) + 1; //둘중 큰 수 다음에 도착하는

    int dist1,dist2;

    if(police1 == 0){
        dist1 = cal_dist(1,1,point[nxt_idx].first,point[nxt_idx].second);
    } else{
        dist1 = cal_dist(point[police1].first,point[police1].second,point[nxt_idx].first,point[nxt_idx].second);
    }

    if(police2 == 0){
        dist2 = cal_dist(N,N,point[nxt_idx].first,point[nxt_idx].second);
    } else{
        dist2 = cal_dist(point[police2].first,point[police2].second,point[nxt_idx].first,point[nxt_idx].second);
    }

    int ret_dist1 = dist1 + cal_min_dist(nxt_idx,police2);
    int ret_dist2 = dist2 + cal_min_dist(police1,nxt_idx);
    dp[police1][police2] = min(ret_dist1,ret_dist2);
    return dp[police1][police2];
}

void print_police(int police1, int police2){
    if(police1 == W || police2 == W){
        return;
    }
//    if(dp[police1][police2] != -1) return dp[police1][police2];
    int nxt_idx = max(police1,police2) + 1; //둘중 큰 수 다음에 도착하는 곳

    int dist1,dist2;

    if(police1 == 0){
        dist1 = cal_dist(1,1,point[nxt_idx].first,point[nxt_idx].second);
    } else{
        dist1 = cal_dist(point[police1].first,point[police1].second,point[nxt_idx].first,point[nxt_idx].second);
    }

    if(police2 == 0){
        dist2 = cal_dist(N,N,point[nxt_idx].first,point[nxt_idx].second);
    } else{
        dist2 = cal_dist(point[police2].first,point[police2].second,point[nxt_idx].first,point[nxt_idx].second);
    }

    int ret_dist1 = dist1 + dp[nxt_idx][police2];
    int ret_dist2 = dist2 + dp[police1][nxt_idx];
    if(ret_dist1 < ret_dist2){
        cout << '1' << "\n";
        print_police(nxt_idx,police2);
    }
    else{
        cout << '2' << "\n";
        print_police(police1,nxt_idx);
    }

//    dp[police1][police2] = min(ret_dist1,ret_dist2);
//    return dp[police1][police2];
}



int main(){
    cin >> N;
    cin >> W;
    for(int i=1; i<=W; i++){
        int a,b;
        cin >> a >> b;
        point.push_back({a,b});
    }

    memset(dp,-1,sizeof(dp));

    cout << cal_min_dist(0,0) << "\n";
    print_police(0,0);







}
