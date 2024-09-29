#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N,L,R;
int arr[101][101];
int arr1[101][101]; //연합한 배열 옮길곳
bool isOpen[101][101];
bool visited[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int day = 0;
bool isConnect(int x, int y){
    bool isCon = false;
    for(int dir =0; dir<4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx <0 || ny <0 || nx >=N || ny>=N) continue;
        if(isOpen[nx][ny] == 1) continue;
        if(abs(arr[x][y] - arr[nx][ny]) >= L && abs(arr[x][y] - arr[nx][ny]) <= R ){
            isOpen[x][y] = 1;
            isOpen[nx][ny] = 1;
            isCon = true;
        }
    }
    return isCon;
}

int main(){
    First

    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    while(true){

        memset(isOpen,0,sizeof(isOpen));
        memset(arr1,0,sizeof(arr1));
        memset(visited,0,sizeof(visited));

        //모든 경우에 대하여 돌림
        for(int i=0; i<N ;i++){
            for(int j=0; j<N; j++){
                //국경선 공유 나라 인구차이 L <= R이면 국경선 오픈
                //오픈하면 다른 테이블을 1처리해서 열어줬다하자

                //전체를 4방향 둘러보면서 찾으면서 열린거 매핑
                if(isConnect(i,j)){
                    //국경선 다 열렸으면 인구 이동 시작(이건 열어놨음)

                    //이동 가능하면 연합(bfs로 다 돌기)
                    queue<pair<int,int>> q;
                    int union_cnt = 0;
                    int union_people = 0;

                    q.push({i,j});
                    visited[i][j] = 1;
                    union_people += arr[i][j];
                    union_cnt ++;

                    while(q.empty()){
                        auto cur = q.front();q.pop();
                        int x = cur.first;
                        int y = cur.second;

                        for(int dir = 0; dir <4; dir++){
                            int nx = x + dx[dir];
                            int ny = y+ dy[dir];
                            if(nx < 0 || ny <0 || nx >=N || ny >=N) continue;
                            if(isOpen[nx][ny]){
                                visited[nx][ny] = 1;
                                union_cnt++;
                                union_people += arr[nx][ny];
                                q.push({nx,ny});
                            }
                        }
                    }
                    //연합 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)
                    int people = union_people / union_cnt;
                    for(int i=0; i<N; i++){
                        for(int j=0; j<N; j++){
                            if(visited[i][j] == 1){
                                arr1[i][j] = people;
                            }
                        }
                    }


                }else{
                    //인구이동 언제까지 일어나냐(국경선이 오픈 안되는 순간 break;
                    //연합 해제 하고 국경선 닫음
                  break;
                }

            }
        }
    }










}