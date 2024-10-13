#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int a[16][16];
int d[16][1<<16]; //현재 위치, 어디 방문했는지
#define INF 987654321

int n;

int full;

int solve(int x, int state) {
    //모든 곳을 다 방문했을때
    //더 들어가는거 대신에 0에 가는 길이를 더해준다
    if (state == full) {
        if (a[x][0]) return a[x][0];
        else return INF;
    }
    //이미 방문했었다면
    if (d[x][state] != -1)return d[x][state];
    d[x][state] = INF;
    for (int i = 0; i < n; i++) {
        if (state & (1 << i))continue; //이미 방문한 경우
        if (a[x][i] == 0)continue; //방문 불가능한 경우
        d[x][state] = min(d[x][state], solve(i, state | (1 << i)) + a[x][i]);
    }
    return d[x][state];
}
int main(){

    cin >> n;
    full = (1<<n) -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    //반드시 초기화
    memset(d,-1,sizeof(d));

    cout << solve(0,1) << "\n";



}
