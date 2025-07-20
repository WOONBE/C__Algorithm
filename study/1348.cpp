#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int R,C;
string arr[51];
vector<pair<int,int>> car;
vector<pair<int,int>> parking;
vector<pair<int,int>> graph[101]; //a에서 b까지 걸리는 거리
bool visited[101];//노드 방문여부 확인
int matched[101]; //매칭여부 확인
int node_num = 1; //노드 번호(하나의 bfs 돈 이후에 증가)
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool OOB(int x, int y){
    return x>=0 && y>=0 && R>x && C>y;
}
void bfs(int x, int y){
    int dist[51][51];
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;

    q.push({x,y});
    dist[x][y] = 0;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        x = cur.first;
        y = cur.second;
        if(arr[x][y] == 'P'){
            for(int i=0; i<parking.size(); i++){
                if(x == parking[i].first && y == parking[i].second){
                    graph[node_num].push_back({i+1,dist[x][y]});
                }
            }
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!OOB(nx,ny)) continue;
            if(arr[nx][ny] == 'X') continue;
            if(dist[nx][ny] != -1) continue;
            q.push({nx,ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}
//이분 매칭 코드
bool dfs(int num, int mid){
    for(auto j : graph[num]){
        if(visited[j.first]) continue;
        if(j.second > mid) continue;
        visited[j.first] = true;

        if(matched[j.first] == -1 || dfs(matched[j.first],mid)){
            matched[j.first] = num;
            return true;
        }
    }
    return false;
}

bool check(int mid) {

    memset(matched, -1, sizeof(matched));
    int count = 0;

    for (int i = 1; i <= car.size(); ++i) {
        memset(visited, false, sizeof(visited));
        if (dfs(i, mid)) {
            count++;
        }
    }
    // 모든 차가 매칭되었는지 여부 반환
    return count == car.size();
}
int main(){
    First

    cin >> R >> C;
    for(int i=0; i<R; i++){
        cin >> arr[i];
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] == 'C'){
                car.push_back({i,j});
            }
            if(arr[i][j] == 'P'){
                parking.push_back({i,j});
            }
        }
    }
    //주차 불가능 여부 판단 1
    if(car.size() > parking.size()){
        cout << -1 << "\n";
        return 0;
    }

    for(auto i : car){
        bfs(i.first,i.second); //bfs를 돌려서 각 노드별 연결 길이를 구한다
        node_num++;
    }

    //주차 불가능 여부 판단 2
    for(int i=1; i<=car.size(); i++){
        if(graph[i].empty()){
            cout << -1 << "\n";
            return 0;
        }
    }
    int left = 0;
    int right = 2500;
    int ans = 987654321;
    while(left < right){
        int mid = (left+right)/2;
        for(int i=1; i<=car.size(); i++){
            if(check(mid)){
                ans = min(ans,mid);
                right  = mid -1;
            }else{
                left = mid + 1;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}