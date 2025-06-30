#include <bits/stdc++.h>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0);


//민트초코우유,민트초코,민트우유,초코우유,우유,초코,민트(M,C,T)순으로
//민트,초코,우유,초코우유,민트우유
int N,T;
string string_arr[55];
int arr[55][55]; //맛 숫자로 저장
int believe[55][55]; // 신앙심저장
int visited[55][55]; // 방문표시
int dx[4] = {-1,1,0,0};//위 아래 왼쪽 오른쪽
int dy[4] = {0,0,-1,1};
int is_defend[55][55]; //맛 같게하는 부분(basic count로 해결)
vector<int> v; //결과값 담아둘 배열
struct student{
    int flavor;
    int belief;
    int x;
    int y;
};
struct Candidate{
    int belief;
    int x;
    int y;
};
bool Candidate_cmp(Candidate a, Candidate b){
    if(a.belief == b.belief){
        if(a.x == b.x){
            return a.y < b.y;
        }
        return a.x < b.x;
    }else return a.belief > b.belief;
}
bool OOB(int x1, int y1){
    if(x1 < 0 || y1 < 0 || x1>=N || y1>=N) return true;
    else return false;
}
int basic_flavor_count(int x){ //각 항목별로 가중치가 같아서 같게 해줘야한다
    int cnt = 0;
    if(x & 1) cnt++;
    if(x & 2) cnt++;
    if(x & 4) cnt++; //비트는 쓰려면 1,2,4로 해야한다
    return cnt;
}
struct cmp{
    bool operator()(student a, student b){
        if(a.flavor == b.flavor){
            if(a.belief == b.belief){
                if(a.x == b.x){
                    return a.y > b.y;
                }
                return a.x > b.x;
            }
            return a.belief < b.belief;
        }
        return a.flavor > b.flavor;
        }
};

//대표자 배열
priority_queue<student,vector<student>,cmp> president;

void breakfast(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            believe[i][j]++;
        }
    }
}
void bfs(int x, int y){
    queue<pair<int,int>> q;
    visited[x][y] = 1;
    q.push({x,y});
    vector<Candidate> candidate;
    candidate.push_back({believe[x][y],x,y});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        x = cur.first;
        y = cur.second;
        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OOB(nx,ny)) continue;
            if(visited[nx][ny]) continue;
            if(arr[nx][ny] == arr[x][y]){
                visited[nx][ny] = 1;
                candidate.push_back({believe[nx][ny],nx,ny});
                q.push({nx,ny});
            }
        }
    }
    //신앙심 넘기는 부분 필요
    sort(candidate.begin(),candidate.end(),Candidate_cmp);
    Candidate student = candidate[0];
    believe[student.x][student.y] += (candidate.size() - 1);
    for(int i=1; i<candidate.size(); i++){
        believe[candidate[i].x][candidate[i].y]--;
    }
    president.push({basic_flavor_count(arr[student.x][student.y]),believe[student.x][student.y],student.x,student.y});
}
void lunch(){
//    while(!president.empty()){
//        president.pop();
//    }
    memset(visited,0,sizeof(visited)); //이부분 처리 안했음
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]) continue;
            bfs(i,j);
        }
    }
}

void dinner(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            is_defend[i][j] = 0;
        }
    }
    while(!president.empty()){
        auto cur = president.top(); president.pop();
        int x = cur.x;
        int y = cur.y;
        if(is_defend[x][y]) continue;//방어 상태면 전파 금지
        int cur_belief = cur.belief;
        int dir = cur_belief % 4;
        int desire = cur_belief - 1; //간절함으로 치환 + 기존 belief 줄여줘야함
        believe[x][y] = 1;
        int nx = x;
        int ny = y;
        while(true){
            nx += dx[dir];
            ny += dy[dir];
            if(OOB(nx,ny) || desire <= 0) break;
            if(arr[x][y] == arr[nx][ny]) continue;
            //전파자의 간절함 x, 전파 대상의 신앙심 y
            if(desire > believe[nx][ny]){ //강한 전파
                arr[nx][ny] = arr[x][y];
                desire -= (believe[nx][ny]+1);
                believe[nx][ny]++;
                is_defend[nx][ny] = 1;
            }else{//약한 전파
                arr[nx][ny] |= arr[x][y];
                believe[nx][ny] += desire;
                is_defend[nx][ny] = 1;
                desire = 0;
                break;
            }
        }
    }
}
void cal_result(){
    int flavor_sums[8] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            flavor_sums[arr[i][j]] += believe[i][j];
        }
    }

    cout << flavor_sums[7] << " "
         << flavor_sums[3] << " "
         << flavor_sums[5] << " "
         << flavor_sums[6] << " "
         << flavor_sums[4] << " "
         << flavor_sums[2] << " "
         << flavor_sums[1] << "\n";
}



int main(){
    First

    cin >> N >> T;
    for(int i=0; i<N; i++){
        cin >> string_arr[i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(string_arr[i][j] == 'M'){
                arr[i][j] = 4;
            }
            if(string_arr[i][j] == 'C'){
                arr[i][j] = 2;
            }
            if(string_arr[i][j] == 'T'){
                arr[i][j] = 1;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> believe[i][j];
        }
    }
    while(T--){
        breakfast();
        lunch();
//        while(!president.empty()){
//            auto cur = president.top();president.pop();
//            cout << cur.flavor << ' '<< cur.belief << ' ' << cur.x << ' ' << cur.y << ' ' <<  "\n";
//        }
        dinner();

//        for(int i=0; i<N; i++){
//            for(int j=0; j<N; j++){
//                cout << arr[i][j] << ' ';
//            }cout << "\n";
//        }cout << "\n";
//
//        for(int i=0; i<N; i++){
//            for(int j=0; j<N; j++){
//                cout << believe[i][j] << ' ';
//            }cout << "\n";
//        }cout << "\n";
        cal_result();
    }
}