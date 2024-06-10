#include <iostream>
#include <utility>
#include <algorithm>


using namespace std;
int visited[10];

int arr[10][10];
int n;
int ans = 1e9;
int start;
void solve(int now, int cost, int cnt){
    if(cnt == n-1){ //마지막 1개 남기고
        if(arr[now][start]){ //만일 돌아오는 길이 있으면
            ans = min(ans, cost+arr[now][start]);
            return;
        }
    }

    for(int i=0; i<n; i++){
        if(arr[now][i] && visited[i] == 0){
            visited[i] = 1;
            solve(i, cost + arr[now][i],cnt+1);
            visited[i] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            start = i;
            visited[i] = 1;
            solve(i,0,0);
            visited[i] = 0;
        }
    }
    cout << ans << "\n";
}
