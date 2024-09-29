#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define First ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int N,L,R;
int arr[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int visited[51][51];
int day = 0;
bool isMove;
void input(){
    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
}
bool isConnect(int x, int y, int nx, int ny){
    if(abs(arr[x][y] - arr[nx][ny]) >= L && abs(arr[x][y] - arr[nx][ny]) <= R ){
        return true;
    }
    return false;
}

int bfs(int x, int y) {
    queue<pair<int, int>> q;

    vector<pair<int, int>> countries;

    q.push({x, y});
    visited[x][y] = 1;
    int people = arr[x][y];
    countries.push_back({x, y}); //값 하나가 빠졌음

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(visited[nx][ny] == 1) continue; //비교 연산자 잘못 작성
            if (isConnect(x, y, nx, ny)) {
                isMove = true;
                visited[nx][ny] = 1;
                people += arr[nx][ny]; //인구수 더해주고
                countries.push_back({nx, ny});
                q.push({nx, ny});
            }
        }

    }

    if (isMove) {
        int newPopulation = people / countries.size(); // 평균 인구 계산
        for (auto [i, j] : countries) {
            arr[i][j] = newPopulation;
        }
    }

    return countries.size();
}

int main(){
    First
    input();

    //여기 while문 작성이 빡셌음
    while(true){
        isMove = false;
        memset(visited,0,sizeof(visited));

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!visited[i][j]){
                    bfs(i,j);
                }
            }
        }

        if(!isMove) break;
        day++;
    }

    cout << day << "\n";
    return 0;
}
