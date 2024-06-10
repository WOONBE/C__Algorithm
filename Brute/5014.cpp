#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int F,S,G,U,D;
int dx[2];
int visited[1000001];
void bfs(){
    queue<int> q;
    q.push(S);
    visited[S] = 1;

    while(!q.empty()){
        auto S = q.front(); q.pop();

        if(S == G){
            cout << visited[S] - 1;
            return;
        }

        for(int i=0; i<2; i++){
            int nx = S + dx[i];
            if(nx<=0 || nx > F) continue; //여기 범위에 주의
            if(visited[nx]) continue;
            visited[nx] = visited[S] + 1;
            q.push(nx);
        }

    }
    cout << "use the stairs";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;
    dx[0] = U;
    dx[1] = -D;
    bfs();

    return 0;

}
