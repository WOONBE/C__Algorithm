#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;
set<string> visited;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string s = "";
int ans = -1;

void input(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            char c;
            cin >> c;
            s += c;
        }
    }
}
int bfs(){
    queue<pair<string ,int>> q;
    visited.insert(s);

    q.push({s,0});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        string now = cur.first;
        int cnt = cur.second;

        if(now == "123456780"){
            ans = cnt;
        }
        int zero = now.find('0'); //0 근방의 수만 이동 가능
        int x = zero/3;
        int y = zero % 3;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <0 || nx>=3 || ny<0 || ny >=3) continue;
            string ns = now;
            swap(ns[x*3+y], ns[nx*3 +ny]);

            if(visited.find(ns) == visited.end()){
                visited.insert(ns);
                q.push({ns, cnt+1});
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    bfs();

    cout << ans;

}
