//
// Created by 김헌우 on 2023/07/04.
//cycle있으면 같은 그룹, n번 이내에 자기 자신으로 돌아오는걸로 cycle여부 판별
//visited여부만 체크해놓으면 매번 만들때보다 시간복잡도가 확 줄어든다
//다음에 다시 보는게 맞음


#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
int state[100005];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void bfs(int x){
    int cur = x;
    while(true){
        state[cur] = x;
        cur = arr[cur];
        // 이번 방문에서 지나간 학생에 도달했을 경우
        if(state[cur] == x){
            while(state[cur] != CYCLE_IN){
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
            // 이전 방문에서 지나간 학생에 도달했을 경우
        else if(state[cur] != 0) return;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        fill(state+1, state+n+1, 0);
        for(int i = 1; i <= n; i++)
            cin >> arr[i];

        for(int i = 1; i <= n; i++){
            if(state[i] == NOT_VISITED) bfs(i);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(state[i] != CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }
}