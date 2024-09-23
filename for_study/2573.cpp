#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<vector<int>> arr(301, vector<int>(301)); //실제 빙하
//vector<vector<int>> visited; //방문 표시
int visited[301][301];
vector<pair<int,int>> ice;
int ice_cnt=0;

//상하좌우 보고 녹이는 함수, 2하나가 안녹음
void melting(){

    vector<vector<int>> tmp(301, vector<int>(301)); //녹일 정보


    //빙하들을 순회하면서 녹인뒤에 녹인 값을 tmp에 저장해서 실제 배열에 나중에 옮기기
    for(int i=0; i<ice.size(); i++){
        int cnt = 0; //근처에 0 몇개인지
        int x = ice[i].first;
        int y = ice[i].second;
        for(int dir=0; dir<4; dir++){

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || ny <0 || nx>=n || ny >= m) continue; //범위 밖이면 무시
            if(arr[nx][ny] == 0){ //근처 값이 0이면 cnt 추가
                cnt++;
            }
        }
        if(arr[x][y] - cnt > 0){
            tmp[x][y] = arr[x][y] - cnt;
        }
        else if(arr[x][y] - cnt <= 0){
            tmp[x][y] = 0;
            ice_cnt--; //실제 빙하 크기 줄임(이 로직이 주석)

        }
    }
    //옮기기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){ //여기 값 오류
            arr[i][j] = tmp[i][j] ;
        }
    }
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout << arr[i][j] << ' ';
//        }
//        cout << "\n";
//    }

}
//dfs 관련 로직에서 오류
//순회하면서 연결성 확인
//void dfs(int x, int y){
//    if(arr[x][y] > 0){
//        if(visited[x][y] != 1){ //와 if에 중괄호 안썼음
//            visited[x][y] = 1;
//            dfs(x,y);
//        }
//
//        }
//}
//
////연결된게 2개 이상일때 true 리턴
//bool isDistract(){
//    int island_cnt = 0;
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            dfs(i,j);
//            island_cnt++;
//        }
//    }
//    if(island_cnt > 1){
//        return false;
//
//    }
//    return true;
//}
// 연결성 확인(처음 로직이 너무 개판임)
void dfs(int x, int y) {
    visited[x][y] = 1; // 방문 처리

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // 범위 밖이면 무시
        if (arr[nx][ny] > 0 && !visited[nx][ny]) { // 방문하지 않았고, 빙하가 있는 경우
            dfs(nx, ny);
        }
    }
}

// 연결된 게 2개 이상일 때 true 리턴
bool isDistract() {
//    memset(visited,0,sizeof(visited)); vector는 memset 사용불가
//    visited.assign(n, vector<int>(m, 0));
    int island_cnt = 0;
    memset(visited,0,sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > 0 && !visited[i][j]) { // 빙하가 있고, 방문하지 않았으면 DFS 실행
                dfs(i, j);
                island_cnt++; // 한 번 DFS를 돌면 하나의 섬을 찾은 것
            }
        }
    }
    return island_cnt > 1; // 섬의 개수가 2개 이상이면 true 반환
}


//입력
void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] > 0){
                ice.push_back({i,j}); //빙하가 있으면 벡터에 in
                ice_cnt++;
            }
        }
    }
}
int main(){
    First

    input();

    int year = 0;
//    ice_cnt = ice.size();
//    while(true){
//        if(ice_cnt == 0){
//            cout << 0 << "\n";
//            break;
//
//        }
//
//        //한번 녹이고
//        melting();
//        year++;
//
//        //분리되었는지 확인
//        if(!isDistract()){
//            cout << year << "\n";
//            break;
//        }
//    }
//    return 0;
    while (true) {
        if (ice_cnt == 0) {
            cout << 0 << "\n";
            break;
        }

        melting(); // 한 번 녹이고
        year++; // 년도 증가
        if (isDistract()) { // 분리되었는지 확인
            cout << year << "\n";
            break;
        }
    }
    return 0;
}
