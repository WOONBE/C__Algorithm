#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N, M, G, R;
int mx_flower = 0;
int arr[51][51]; //원 배열
int arr2[51][51]; //원 배열 복사해놓을 배열
int tme[51][51]; //시간 저장할 배열
queue<pair<int,int>> q; //bfs 한번 돌릴때 쓰는 큐
queue<pair<int,int>> q2; //돌린 이후에 넣는 값을 저장할 큐
vector<pair<int,int>> canPlant;
vector<int> state;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs() {
    int now = 1;
    int tans = 0;
    while (true) {
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (arr[x][y] == 5)continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
                if (arr[nx][ny] == 0)continue;
                if (arr[nx][ny] <= 2) {
                    arr[nx][ny] = arr[x][y]; //3,4로 세팅해놓은걸로 옮김
                    tme[nx][ny] = now;
                    q2.push({ nx,ny });
                    continue;
                }
                if (arr[nx][ny] == 5)continue;
                if (tme[nx][ny] != now)continue;
                if (arr[nx][ny] != arr[x][y]) {
                    tans++;
                    arr[nx][ny] = 5;
                }
            }
        }
        now++;
        if (q2.empty())break;
        while (!q2.empty()) {
            q.push(q2.front());
            q2.pop();
        }
    }
    mx_flower = max(mx_flower, tans);
}

void dfs(int idx,int g_cnt, int r_cnt) {
    if(idx >= canPlant.size()) {
        if(g_cnt == G && r_cnt == R) {
            //정해졌으면 배열 초기화하고 bfs
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    arr[i][j] = arr2[i][j];
                    tme[i][j] = 0;
                }
            }
            for(int i=0; i<canPlant.size(); i++) {
                int x = canPlant[i].first;
                int y = canPlant[i].second;
                if(state[i] >= 1) { //배양액이 있으면
                    arr[x][y] = state[i] + 2; //기존 배양액도 안의 세팅 바꿈
                    q.push({x,y});
                }
            }
            bfs();
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        state.push_back(i);
        if (i == 1) {
            dfs(idx + 1, g_cnt + 1, r_cnt);
        } else if (i == 2) {
            dfs(idx + 1, g_cnt, r_cnt + 1);
        } else {
            dfs(idx + 1, g_cnt, r_cnt);
        }
        state.pop_back();  // 추가된 상태를 제거
    }
}

int main() {
    First
    cin >> N >> M >> G >> R;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
            arr2[i][j] = arr[i][j];
            if(arr[i][j] == 2) {
                canPlant.push_back({i,j});
            }
        }
    }
    dfs(0,0,0);
    cout << mx_flower << "\n";
}
